// Vraag 12: default constructor
// Waar: SimpleTask()

// Vraag 13: parameterized constructor
// Waar: SimpleTask(const std::string&, const std::string&, unsigned char)

// Vraag 14: copy constructor
// Waar: SimpleTask(const SimpleTask&)

// Vraag 18: inheritance + polymorphism
// Waar: SimpleTask erft van Task en override type() en print().


#pragma once

#include "Task.h"

namespace taskmgr {

// Concrete implementatie van een eenvoudige taak.
// Inheritance: SimpleTask ERFT alle data en functies van Task.
class SimpleTask : public Task {
public:
    // Default constructor: gebruikt de default van de base class
    SimpleTask();

    // Parameter constructor: forwarded naar de base class constructor
    SimpleTask(const std::string& title,
               const std::string& description,
               unsigned char priority);

    // Copy constructor: forwarded naar de base class copy constructor
    SimpleTask(const SimpleTask& other);

    // Destructor: override (hoeft niets extra te doen)
    ~SimpleTask() override;

    // Concrete implementaties van de abstracte functies van Task
    TaskType type() const override;
    void print(std::ostream& os) const override;
};

} // namespace taskmgr
