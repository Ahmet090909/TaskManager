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
    : m_id(s_nextId++),
    m_title(other.m_title),
    m_description(other.m_description),
    m_priority(other.m_priority),
    m_done(other.m_done) {}

Task::~Task() = default;

void Task::setTitle(const std::string& title) { this->m_title = title; }
void Task::setDescription(const std::string& description) { m_description = description; }
void Task::setPriority(unsigned char priority) {
    if (priority > 10) priority = 10;
    m_priority = priority;
}
void Task::setDone(bool done) { m_done = done; }

std::ostream& operator<<(std::ostream& os, const Task& t) {
    t.print(os);    // later overladen in afgeleide klassen
    return os;
}

} // namespace taskmgr
