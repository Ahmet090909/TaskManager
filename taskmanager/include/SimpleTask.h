#pragma once

#include "Task.h"

namespace taskmgr {

// Afgeleide klasse van Task
class SimpleTask : public Task {
public:
    // default ctor
    SimpleTask();

    // parameter ctor
    SimpleTask(const std::string& title,
               const std::string& description,
               unsigned char priority);

    // copy ctor
    SimpleTask(const SimpleTask& other);

    // destructor
    ~SimpleTask() override;

    // overrides van pure virtual functies
    TaskType type() const override;
    void print(std::ostream& os) const override;
};

} // namespace taskmgr
