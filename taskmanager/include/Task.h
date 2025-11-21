#pragma once

#include <string>
#include <iostream>

namespace taskmgr {

enum class TaskType : unsigned char {
    Simple = 0
};

class Task {
protected:
    static unsigned int s_nextId;

    const unsigned int m_id;
    std::string m_title;
    std::string m_description;
    unsigned char m_priority; // 0-10
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

    virtual TaskType type() const = 0;
    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Task& t);
};

} // namespace taskmgr

