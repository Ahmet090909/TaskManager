#include <iostream>
#include "TaskManager.h"
#include "SimpleTask.h"

int main() {
    taskmgr::TaskManager manager;


    manager.addTask(new taskmgr::SimpleTask(
        "C++ opdracht", "Task manager project afwerken", 8
        ));
    manager.addTask(new taskmgr::SimpleTask(
        "Afwassen", "Even de keuken opruimen", 3
        ));

    std::cout << "Alle taken:\n";
    manager.listTasks();


    taskmgr::Task* first = manager.findTaskById(1);
    if (first != nullptr) {
        first->setDone(true);
    }

    std::cout << "\nNiet-afgewerkte taken:\n";
    manager.listTasks(false);

    // save naar bestand
    manager.saveToFile("tasks.txt");
    std::cout << "\nTaken opgeslagen in tasks.txt\n";

    return 0;
}
