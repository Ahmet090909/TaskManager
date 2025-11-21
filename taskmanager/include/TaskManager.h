#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Task.h"

namespace taskmgr {

// TaskManager "heeft" een verzameling van Tasks (object composition).
class TaskManager {
    // Container class (std::vector) met pointers naar abstracte Task
    std::vector<Task*> m_tasks;

public:
    TaskManager() = default;

    // Destructor: hier centraliseren we de verantwoordelijkheid
    // voor het opruimen van alle dynamische tasks (new/delete).
    ~TaskManager();

    // Kopiëren is uitgeschakeld: een echte deep copy is buiten scope.
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    // Neemt ownership van de pointer (verwacht resultaat van new)
    void addTask(Task* task);

    bool removeTaskById(unsigned int id);

    Task* findTaskById(unsigned int id);
    const Task* findTaskById(unsigned int id) const;

    // Default value: standaard tonen we ook done-taken
    void listTasks(bool showDone = true) const;

    // File I/O
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // Template-functie: voert een lambda of functor uit op alle tasks.
    template<typename Predicate>
    void forEachTask(Predicate pred) const {
        for (const Task* t : m_tasks) {
            if (t != nullptr) {
                pred(*t);  // const reference naar Task
            }
        }
    }
};

} // namespace taskmgr
