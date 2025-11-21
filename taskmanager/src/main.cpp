#include <iostream>
#include "TaskManager.h"
#include "ConsoleUI.h"

int main() {
    try {
        taskmgr::TaskManager manager;      // business logica
        taskmgr::ui::ConsoleUI::run(manager); // UI-laag
    } catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}
