#include "Task.h"

namespace taskmgr {

// Initialisatie van de statische ID-teller
unsigned int Task::s_nextId = 1;

// Default constructor: gebruikt member-init-lijst
Task::Task()
    : m_id(s_nextId++),
    m_title("New task"),
    m_description(""),
    m_priority(5),
    m_done(false) {}

// Parameter constructor
Task::Task(const std::string& title,
           const std::string& description,
           unsigned char priority)
    : m_id(s_nextId++),
    m_title(title),
    m_description(description),
    m_priority(priority),
    m_done(false) {}

// Copy constructor: kopieert alle velden, maar geeft een NIEUWE id
Task::Task(const Task& other)
    : m_id(s_nextId++),
    m_title(other.m_title),
    m_description(other.m_description),
    m_priority(other.m_priority),
    m_done(other.m_done) {}

Task::~Task() = default;

void Task::setTitle(const std::string& title) {
    // bewust gebruik van this-> (komt in puntenlijst)
    this->m_title = title;
}

void Task::setDescription(const std::string& description) {
    m_description = description;
}

void Task::setPriority(unsigned char priority) {
    // eenvoudige validatie: priority max 10
    if (priority > 10) priority = 10;
    m_priority = priority;
}

void Task::setDone(bool done) {
    m_done = done;
}

std::ostream& operator<<(std::ostream& os, const Task& t) {
    // Dynamisch polymorfisme: roept de print() van de concrete subklasse op
    t.print(os);
    return os;
}

} // namespace taskmgr
