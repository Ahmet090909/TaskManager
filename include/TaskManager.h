// Vraag 25: useful template function
// Waar: template functie forEachTask(Predicate).

// Vraag 34: modern call-by-reference
// Waar: editTaskById(unsigned int, const std::function<void(Task&)>&).

// Vraag 41: useful usage of threads
// Waar: autosave thread via std::thread en std::atomic<bool>.


#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

#include "Task.h"

namespace taskmgr {

class TaskManager {
private:
    std::vector<Task*> m_tasks;

    // autosave thread (rubric threads)
    mutable std::mutex m_mutex;
    std::thread m_autoThread;
    std::atomic<bool> m_running{false};
    std::string m_autoFile;
    std::chrono::seconds m_interval{15};

public:
    TaskManager() = default;
    ~TaskManager();

    TaskManager(const TaskManager&) = delete;
    TaskManager& operator=(const TaskManager&) = delete;

    void addTask(Task* task);
    bool removeTaskById(unsigned int id);

    Task* findTaskById(unsigned int id);
    const Task* findTaskById(unsigned int id) const;

    bool editTaskById(unsigned int id, const std::function<void(Task&)>& editor);

    void listTasks(bool showDone = true) const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void startAutoSave(const std::string& filename,
                       std::chrono::seconds interval = std::chrono::seconds(15));
    void stopAutoSave();

    template<typename Predicate>
    void forEachTask(Predicate pred) const {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (const Task* t : m_tasks) {
            if (t != nullptr) pred(*t);
        }
    }
};

} // namespace taskmgr
