// Vraag 2: clean main
// Waar: main bevat enkel het opstarten van QApplication en het tonen van MainWindow.
// Er staat geen business logic of applicatielogica in main.

#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    taskmgr::ui::MainWindow w;
    w.show();

    return app.exec();
}
