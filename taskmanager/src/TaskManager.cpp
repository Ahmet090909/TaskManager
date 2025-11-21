#include "TaskManager.h"
#include "SimpleTask.h"   // voor loadFromFile
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace taskmgr {

TaskManager::~TaskManager() {
    // ruim alle dynamisch gealloceerde tasks op
    for (Task* t : m_tasks) {
        delete t;
    }
    m_tasks.clear();
}

void TaskManager::addTask(Task* task) {
    if (task == nullptr) {
        throw std::invalid_argument("TaskManager::addTask got nullptr");
    }
    m_tasks.push_back(task);
}

bool TaskManager::removeTaskById(unsigned int id) {
    for (auto it = m_tasks.begin(); it != m_tasks.end(); ++it) {
        if (*it && (*it)->id() == id) {
            delete *it;
            m_tasks.erase(it);
            return true;
        }
    }
    return false;
}

Task* TaskManager::findTaskById(unsigned int id) {
    for (Task* t : m_tasks) {
        if (t && t->id() == id) {
            return t;
        }
    }
    return nullptr;
}

const Task* TaskManager::findTaskById(unsigned int id) const {
    for (const Task* t : m_tasks) {
        if (t && t->id() == id) {
            return t;
        }
    }
    return nullptr;
}

void TaskManager::listTasks(bool showDone) const {
    // lambda + templatefunctie
    forEachTask([showDone](const Task& t) {
        if (!showDone && t.isDone()) {
            return; // overslaan
        }
        std::cout << t << "\n";
    });
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    // heel simpele tekstrepresentatie: type;prio;done;title;description
    forEachTask([&out](const Task& t) {
        out << 'S' << ';'                  // S = SimpleTask
            << static_cast<int>(t.priority()) << ';'
            << (t.isDone() ? 1 : 0) << ';'
            << t.title() << ';'
            << t.description() << '\n';
    });
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {

        return;
    }

    // eerst oude taken opruimen
    for (Task* t : m_tasks) {
        delete t;
    }
    m_tasks.clear();

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        char typeChar{};
        ss >> typeChar;
        if (ss.peek() == ';') ss.get(); // ; weggooien

        if (typeChar == 'S') {
            std::string prioStr, doneStr, title, desc;

            std::getline(ss, prioStr, ';');
            std::getline(ss, doneStr, ';');
            std::getline(ss, title, ';');
            std::getline(ss, desc);

            unsigned char prio =
                static_cast<unsigned char>(std::stoi(prioStr));
            bool done = (doneStr == "1");

            auto* task = new SimpleTask(title, desc, prio);
            task->setDone(done);
            addTask(task);
        }

    }
}

} // namespace taskmgr
