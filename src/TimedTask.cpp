// Vraag 14: copy constructor
// Waar: TimedTask(const TimedTask&)

// Vraag 15: destructor
// Waar: ~TimedTask()

// Vraag 16: member initialization list
// Waar: m_dueDate wordt geïnitialiseerd in initializer list.


#include "TimedTask.h"

namespace taskmgr {

    TimedTask::TimedTask()
        : Task(), m_dueDate("geen datum") {}

    TimedTask::TimedTask(const std::string& title,
                         const std::string& description,
                         unsigned char priority,
                         const std::string& dueDate)
        : Task(title, description, priority),
          m_dueDate(dueDate) {}

    TimedTask::TimedTask(const TimedTask& other)
        : Task(other),
          m_dueDate(other.m_dueDate) {}

    TimedTask::~TimedTask() = default;

    void TimedTask::setDueDate(const std::string& dueDate) {
        m_dueDate = dueDate;
    }

    TaskType TimedTask::type() const {
        return TaskType::Timed;
    }

    void TimedTask::print(std::ostream& os) const {
        os << "[Timed]  #" << id()
           << " (prio " << static_cast<int>(priority()) << ") "
           << (isDone() ? "[DONE] " : "")
           << title() << " - " << description()
           << "  (due: " << m_dueDate << ")";
    }

} // namespace taskmgr
