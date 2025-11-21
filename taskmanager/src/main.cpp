#include <iostream>
#include "SimpleTask.h"

int main() {
    taskmgr::SimpleTask t1("C++ opdracht", "Task manager in OOP bouwen", 8);
    taskmgr::SimpleTask t2("Test taak", "Even inheritance testen", 5);

    std::cout << t1 << "\n";
    std::cout << t2 << "\n";

    t1.setDone(true);
    std::cout << "Na done:\n";
    std::cout << t1 << "\n";

    return 0;
}
