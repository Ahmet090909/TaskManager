#pragma once

#include <string>
#include <iostream>

namespace taskmgr {

// Efficiënt type voor het soort task (1 byte)
enum class TaskType : unsigned char {
    Simple = 0,
    // later bv. Timed = 1
};

// Abstracte basis-klasse:
// - definieert WAT elke taak moet kunnen (id, titel, priority, done, print)
// - laat open HOE een concrete task zich exact gedraagt
class Task {
protected:
    // gedeelde teller voor unieke IDs (class-level state)
    static unsigned int s_nextId;

    // const id: wordt één keer gezet via member-init-list
    const unsigned int m_id;

    // data van de taak worden afgeschermd (encapsulation)
    std::string m_title;
    std::string m_description;
    unsigned char m_priority; // 0–10, compact type
    bool m_done;

public:
    // Default constructor: maakt een "lege" maar geldige taak
    Task();

    // Parameter constructor: gebruiker kan meteen titel/omschrijving/prio zetten
    Task(const std::string& title,
         const std::string& description,
         unsigned char priority);

    // Copy constructor: kopieert de inhoud, maar geeft een nieuwe unieke id
    Task(const Task& other);

    // Virtual destructor: nodig zodat delete via Task* correct werkt (polymorfisme)
    virtual ~Task();

    // Getters (const => garanderen dat ze object niet wijzigen)
    inline unsigned int id() const { return m_id; }
    inline const std::string& title() const { return m_title; }
    inline const std::string& description() const { return m_description; }
    inline unsigned char priority() const { return m_priority; }
    inline bool isDone() const { return m_done; }

    // Setters: gecontroleerde toegang tot de membervariabelen
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);
    void setPriority(unsigned char priority);
    void setDone(bool done = true); // default value

    // Pure virtual functies: maken van Task een ABSTRACTE klasse.
    // Elke concrete task MOET deze functies implementeren.
    virtual TaskType type() const = 0;
    virtual void print(std::ostream& os) const = 0;

    // Friend operator<< gebruikt dynamisch polymorfisme:
    // hij roept print() op van de afgeleide klasse.
    friend std::ostream& operator<<(std::ostream& os, const Task& t);
};

} // namespace taskmgr
