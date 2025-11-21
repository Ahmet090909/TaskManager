#include "SimpleTask.h"

namespace taskmgr {

    SimpleTask::SimpleTask()
        : Task() {}

    SimpleTask::SimpleTask(const std::string& title,
                           const std::string& description,
                           unsigned char priority)
        : Task(title, description, priority) {}

    SimpleTask::SimpleTask(const SimpleTask& other)
        : Task(other) {}

    SimpleTask::~SimpleTask() = default;

    TaskType SimpleTask::type() const {
        return TaskType::Simple;
    }

    void SimpleTask::print(std::ostream& os) const {
        os << "[Simple] #" << id()
           << " (prio " << static_cast<int>(priority()) << ") "
           << (isDone() ? "[DONE] " : "")
           << title() << " - " << description();
    }

} // namespace taskmgr
