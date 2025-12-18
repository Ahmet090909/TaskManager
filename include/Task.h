// Vraag 12: at least 2 default constructors
// Waar: Task() is een default constructor.

// Vraag 13: at least 2 parameterized constructors
// Waar: Task(const std::string&, const std::string&, unsigned char)

// Vraag 14: at least 2 copy constructors
// Waar: Task(const Task&)

// Vraag 15: at least 2 destructors
// Waar: virtual ~Task()

// Vraag 16: member initialization in constructors
// Waar: alle constructors gebruiken initializer lists (: m_id(...), m_title(...), ...)

// Vraag 18: useful proven (dynamic) polymorphism
// Waar: Task is een abstracte base class met pure virtual functies type() en print().

// Vraag 23: useful getters and setters
// Waar: title(), setTitle(), description(), setDescription(), isDone(), setDone()

// Vraag 24: correct usage of inline function
// Waar: inline getters in de header.

// Vraag 26: useful friend function
// Waar: operator<< is gedeclareerd als friend van Task.



#pragma once

#include <string>
#include <iostream>

namespace taskmgr {

// Efficiënt type voor het soort task (1 byte)
enum class TaskType : unsigned char {
    Simple = 0,
    Timed  = 1   // taak met deadline
};

// Abstracte basis-klasse:
// - definieert WAT elke taak moet kunnen (id, titel, priority, done, print)
// - concrete klassen (SimpleTask, TimedTask) vullen HOE in.
class Task {
protected:
    static unsigned int s_nextId;

    const unsigned int m_id;
    std::string m_title;
    std::string m_description;
    unsigned char m_priority; // 0–10
    bool m_done;

public:
    Task();
    Task(const std::string& title,
         const std::string& description,
         unsigned char priority);
    Task(const Task& other);
    virtual ~Task();

    inline unsigned int id() const { return m_id; }
    inline const std::string& title() const { return m_title; }
    inline const std::string& description() const { return m_description; }
    inline unsigned char priority() const { return m_priority; }
    inline bool isDone() const { return m_done; }

    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setPriority(unsigned char priority);
    void setDone(bool done = true);

    // pure virtual → Task is abstract
    virtual TaskType type() const = 0;
    virtual void print(std::ostream& os) const = 0;

    // gebruikt polymorfisme om correct afgeleide print() te roepen
    friend std::ostream& operator<<(std::ostream& os, const Task& t);
};

} // namespace taskmgr
