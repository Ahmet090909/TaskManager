// Vraag 32: dynamic memory allocation (new)
// Waar: taken worden aangemaakt met new SimpleTask / new TimedTask.

// Vraag 33: dynamic memory removing (delete)
// Waar: delete in destructor, removeTaskById en clearAll.

// Vraag 36: useful container class
// Waar: std::vector<Task*> wordt gebruikt.

// Vraag 38: useful modern file-I/O
// Waar: std::ifstream en std::ofstream in saveToFile/loadFromFile.

// Vraag 39: useful exception handling
// Waar: throw std::runtime_error bij fout openen van bestand.

// Vraag 40: useful usage of lambda function
// Waar: lambda’s gebruikt in editTaskById en forEachTask.

// Vraag 37: useful usage of nullptr
// Waar: pointers worden gecontroleerd op nullptr voor gebruik.



#include "TaskManager.h"
#include "SimpleTask.h"
#include "TimedTask.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace taskmgr {

TaskManager::~TaskManager() {
    stopAutoSave();

    std::lock_guard<std::mutex> lock(m_mutex);
    for (Task* t : m_tasks) delete t;
    m_tasks.clear();
}

void TaskManager::addTask(Task* task) {
    if (!task) throw std::invalid_argument("TaskManager::addTask got nullptr");
    std::lock_guard<std::mutex> lock(m_mutex);
    m_tasks.push_back(task);
}

bool TaskManager::removeTaskById(unsigned int id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (auto it = m_tasks.begin(); it != m_tasks.end(); ++it) {
        if (*it && (*it)->id() == id) {
            delete *it;          // delete (rubric)
            m_tasks.erase(it);
            return true;
        }
    }
    return false;
}

Task* TaskManager::findTaskById(unsigned int id) {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (Task* t : m_tasks) if (t && t->id() == id) return t;
    return nullptr;
}

const Task* TaskManager::findTaskById(unsigned int id) const {
    std::lock_guard<std::mutex> lock(m_mutex);
    for (const Task* t : m_tasks) if (t && t->id() == id) return t;
    return nullptr;
}

bool TaskManager::editTaskById(unsigned int id, const std::function<void(Task&)>& editor) {
    if (!editor) return false;
    std::lock_guard<std::mutex> lock(m_mutex);
    for (Task* t : m_tasks) {
        if (t && t->id() == id) {
            editor(*t);
            return true;
        }
    }
    return false;
}

void TaskManager::listTasks(bool showDone) const {
    forEachTask([showDone](const Task& t) {
        if (!showDone && t.isDone()) return;
        std::cout << t << "\n";
    });
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Could not open file for writing: " + filename);

    // Formaat:
    // S;prio;done;title;description
    // T;prio;done;title;description;dueDate
    forEachTask([&out](const Task& t) {
        const unsigned char prio = t.priority();
        const bool done = t.isDone();
        const std::string& title = t.title();
        const std::string& desc  = t.description();

        if (t.type() == TaskType::Simple) {
            out << 'S' << ';'
                << static_cast<int>(prio) << ';'
                << (done ? 1 : 0) << ';'
                << title << ';'
                << desc << '\n';
        } else if (t.type() == TaskType::Timed) {
            auto const* timed = dynamic_cast<const TimedTask*>(&t);
            if (timed) {
                out << 'T' << ';'
                    << static_cast<int>(prio) << ';'
                    << (done ? 1 : 0) << ';'
                    << title << ';'
                    << desc << ';'
                    << timed->dueDate() << '\n';
            }
        }
    });
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;

    {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (Task* t : m_tasks) delete t;
        m_tasks.clear();
    }

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        char typeChar{};
        ss >> typeChar;
        if (ss.peek() == ';') ss.get();

        if (typeChar == 'S') {
            std::string prioStr, doneStr, title, desc;
            std::getline(ss, prioStr, ';');
            std::getline(ss, doneStr, ';');
            std::getline(ss, title, ';');
            std::getline(ss, desc);

            const unsigned char prio = static_cast<unsigned char>(std::stoi(prioStr));
            const bool done = (doneStr == "1");

            auto* task = new SimpleTask(title, desc, prio);
            task->setDone(done);
            addTask(task);
        }
        else if (typeChar == 'T') {
            std::string prioStr, doneStr, title, desc, due;
            std::getline(ss, prioStr, ';');
            std::getline(ss, doneStr, ';');
            std::getline(ss, title, ';');
            std::getline(ss, desc, ';');
            std::getline(ss, due);

            const unsigned char prio = static_cast<unsigned char>(std::stoi(prioStr));
            const bool done = (doneStr == "1");

            // ✅ juiste ctor volgorde volgens jouw TimedTask.h:
            // TimedTask(title, description, priority, dueDate)
            auto* task = new TimedTask(title, desc, prio, due);
            task->setDone(done);
            addTask(task);
        }
    }
}

void TaskManager::startAutoSave(const std::string& filename, std::chrono::seconds interval) {
    stopAutoSave();
    m_autoFile = filename;
    m_interval = interval;
    m_running.store(true);

    m_autoThread = std::thread([this]() {
        while (m_running.load()) {
            try {
                this->saveToFile(m_autoFile);
            } catch (...) {
                // autosave errors: ignore (app blijft draaien)
            }
            std::this_thread::sleep_for(m_interval);
        }
    });
}

void TaskManager::stopAutoSave() {
    m_running.store(false);
    if (m_autoThread.joinable()) m_autoThread.join();
}

} // namespace taskmgr
