#pragma once

#include "Task.h"
#include <string>

namespace taskmgr {

// TimedTask is een taak met een extra veld: due date.
// Dit demonstreert extra inheritance/polymorfisme t.o.v. SimpleTask.
class TimedTask : public Task {
    std::string m_dueDate; // bvb. "2025-12-31 23:59"

public:
    // default ctor
    TimedTask();

    // parameter ctor
    TimedTask(const std::string& title,
              const std::string& description,
              unsigned char priority,
              const std::string& dueDate);

    // copy ctor
    TimedTask(const TimedTask& other);

    // destructor
    ~TimedTask() override;

    // extra getter/setter
    const std::string& dueDate() const { return m_dueDate; }
    void setDueDate(const std::string& dueDate);

    // overrides van Task
    TaskType type() const override;
    void print(std::ostream& os) const override;
};

} // namespace taskmgr
