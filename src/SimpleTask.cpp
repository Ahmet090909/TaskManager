#include "SimpleTask.h"

namespace taskmgr {

    SimpleTask::SimpleTask()
        : Task() {} // constructor forwarding

    SimpleTask::SimpleTask(const std::string& title,
                           const std::string& description,
                           unsigned char priority)
        : Task(title, description, priority) {} // constructor forwarding

    SimpleTask::SimpleTask(const SimpleTask& other)
        : Task(other) {} // copy ctor forwarding

    SimpleTask::~SimpleTask() = default;

    TaskType SimpleTask::type() const {
        return TaskType::Simple;
    }

    void SimpleTask::print(std::ostream& os) const {
        // Gebruikt enkel de publieke interface van Task (encapsulation blijft)
        os << "[Simple] #" << id()
           << " (prio " << static_cast<int>(priority()) << ") "
           << (isDone() ? "[DONE] " : "")
           << title() << " - " << description();
    }

} // namespace taskmgr
