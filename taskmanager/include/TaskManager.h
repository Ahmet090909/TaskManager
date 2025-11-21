#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Task.h"

namespace taskmgr {

class TaskManager {
    std::vector<Task*> m_tasks;  // object composition: manager HEEFT tasks

public:
    TaskManager() = default;

    // destructor: ruim alle dynamic memory op
    ~TaskManager();

    // geen copy voor nu (zou deep copy moeten doen)
    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    // neemt ownership van de pointer (moet van new komen)
    void addTask(Task* task);

    bool removeTaskById(unsigned int id);

    Task* findTaskById(unsigned int id);
    const Task* findTaskById(unsigned int id) const;

    // toon alle taken
    void listTasks(bool showDone = true) const;

    // file I/O
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    // templatefunctie: laat een lambda iets doen met elke taak
    template<typename Predicate>
    void forEachTask(Predicate pred) const {
        for (const Task* t : m_tasks) {
            if (t != nullptr) {
                pred(*t);
            }
        }
    }
};

} // namespace taskmgr
