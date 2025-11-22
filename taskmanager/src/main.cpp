#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    taskmgr::ui::MainWindow w;
    w.show();

    return app.exec();
}
