#include "ConsoleUI.h"
#include "SimpleTask.h"
#include <iostream>
#include <limits>

namespace taskmgr::ui {

static void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ConsoleUI::run(taskmgr::TaskManager& manager) {
    bool quit = false;

    while (!quit) {
        std::cout << "\n=== Task Manager ===\n";
        std::cout << "1. Toon alle taken\n";
        std::cout << "2. Voeg simple task toe\n";
        std::cout << "3. Verwijder task\n";
        std::cout << "4. Markeer task als done\n";
        std::cout << "5. Save naar bestand\n";
        std::cout << "6. Load uit bestand\n";
        std::cout << "0. Stop\n";
        std::cout << "> ";

        int choice{};
        if (!(std::cin >> choice)) {
            std::cin.clear();
            clearInput();
            std::cout << "Ongeldige input.\n";
            continue;
        }
        clearInput();

        try {
            if (choice == 1) {
                manager.listTasks();
            } else if (choice == 2) {
                std::string title, desc;
                int prio;

                std::cout << "Titel: ";
                std::getline(std::cin, title);
                std::cout << "Beschrijving: ";
                std::getline(std::cin, desc);
                std::cout << "Prioriteit (0-10): ";
                std::cin >> prio;
                clearInput();

                manager.addTask(new taskmgr::SimpleTask(
                    title, desc, static_cast<unsigned char>(prio)
                    ));
            } else if (choice == 3) {
                unsigned int id;
                std::cout << "ID om te verwijderen: ";
                std::cin >> id;
                clearInput();

                if (manager.removeTaskById(id)) {
                    std::cout << "Task verwijderd.\n";
                } else {
                    std::cout << "Task niet gevonden.\n";
                }
            } else if (choice == 4) {
                unsigned int id;
                std::cout << "ID om als done te markeren: ";
                std::cin >> id;
                clearInput();

                Task* t = manager.findTaskById(id);
                if (t) {
                    t->setDone(true);
                    std::cout << "Task gemarkeerd als done.\n";
                } else {
                    std::cout << "Task niet gevonden.\n";
                }
            } else if (choice == 5) {
                std::string filename;
                std::cout << "Bestandsnaam (bv. tasks.txt): ";
                std::getline(std::cin, filename);
                if (filename.empty()) filename = "tasks.txt";
                manager.saveToFile(filename);
                std::cout << "Opgeslagen.\n";
            } else if (choice == 6) {
                std::string filename;
                std::cout << "Bestandsnaam (bv. tasks.txt): ";
                std::getline(std::cin, filename);
                if (filename.empty()) filename = "tasks.txt";
                manager.loadFromFile(filename);
                std::cout << "Geleden.\n";
            } else if (choice == 0) {
                quit = true;
            } else {
                std::cout << "Onbekende keuze.\n";
            }
        } catch (const std::exception& ex) {
            std::cerr << "Fout: " << ex.what() << "\n";
        }
    }
}

} // namespace taskmgr::ui
