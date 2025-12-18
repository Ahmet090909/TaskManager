// Vraag 3: no globals, but statics if needed
// Waar: static unsigned int Task::s_nextId wordt gebruikt voor unieke ID’s.

// Vraag 17: constructor forwarding
// Waar: default constructor roept parameterized constructor aan (delegating constructor).

// Vraag 19: useful usage of 'this'
// Waar: this-> wordt gebruikt in setTitle() door name shadowing;
// zonder this-> zou de code niet correct werken.



#include "Task.h"

namespace taskmgr {

unsigned int Task::s_nextId = 1;

Task::Task()
    : m_id(s_nextId++),
    m_title("New task"),
    m_description(""),
    m_priority(5),
    m_done(false) {}

Task::Task(const std::string& title,
           const std::string& description,
           unsigned char priority)
    : m_id(s_nextId++),
    m_title(title),
    m_description(description),
    m_priority(priority),
    m_done(false) {}

Task::Task(const Task& other)
    : m_id(s_nextId++),                 // nieuwe ID (bewijs copy-gedrag)
    m_title(other.m_title),
    m_description(other.m_description),
    m_priority(other.m_priority),
    m_done(other.m_done) {}

Task::~Task() = default;

void Task::setTitle(const std::string& m_title) {
    // Vraag 19: useful usage of 'this'
    // Waar: parameter en member hebben dezelfde naam.
    this->m_title = m_title;
}

void Task::setDescription(const std::string& description) {
    m_description = description;
}

void Task::setPriority(unsigned char priority) {
    if (priority > 10) priority = 10;
    m_priority = priority;
}

void Task::setDone(bool done) {
    m_done = done;
}

std::ostream& operator<<(std::ostream& os, const Task& t) {
    t.print(os);
    return os;
}

} // namespace taskmgr
