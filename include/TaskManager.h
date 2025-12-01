#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Task.h"

namespace taskmgr {
// Klasse die alle taken beheert: toevoegen, verwijderen, opslaan en laden.

class TaskManager {
    std::vector<Task*> m_tasks;

public:
    TaskManager() = default;
    ~TaskManager();

    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    void addTask(Task* task);
    bool removeTaskById(unsigned int id);

    Task* findTaskById(unsigned int id);
    const Task* findTaskById(unsigned int id) const;

    void listTasks(bool showDone = true) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

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
