#include "TaskManager.h"
#include "SimpleTask.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace taskmgr {

TaskManager::~TaskManager() {
    // Clean up: alle dynamisch gealloceerde tasks vrijgeven
    for (Task* t : m_tasks) {
        delete t;
    }
    m_tasks.clear();
}

void TaskManager::addTask(Task* task) {
    if (task == nullptr) {
        // Nuttige exception ipv silent fail
        throw std::invalid_argument("TaskManager::addTask got nullptr");
    }
    m_tasks.push_back(task);
}

bool TaskManager::removeTaskById(unsigned int id) {
    for (auto it = m_tasks.begin(); it != m_tasks.end(); ++it) {
        if (*it && (*it)->id() == id) {
            delete *it;        // dynamic memory verwijderen
            m_tasks.erase(it); // pointer uit container verwijderen
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
    return nullptr; // expliciet gebruik van nullptr
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
    // Lambda + templatefunctie: functional style iteratie over alle taken
    forEachTask([showDone](const Task& t) {
        if (!showDone && t.isDone()) {
            return; // done-tasks overslaan
        }
        std::cout << t << "\n";
    });
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        // Exception bij I/O fout
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    // Eenvoudig tekstformaat: type;priority;done;title;description
    forEachTask([&out](const Task& t) {
        out << 'S' << ';'  // S = SimpleTask
            << static_cast<int>(t.priority()) << ';'
            << (t.isDone() ? 1 : 0) << ';'
            << t.title() << ';'
            << t.description() << '\n';
    });
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        // Geen bestand? Dan laten we het stilletjes zitten.
        return;
    }

    // Oude taken opruimen vóór we nieuwe inladen
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
        if (ss.peek() == ';') ss.get(); // ';' verwijderen

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
            addTask(task); // hergebruik van addTask (encapsulation)
        }
        // later: andere types zoals TimedTask
    }
}

} // namespace taskmgr
