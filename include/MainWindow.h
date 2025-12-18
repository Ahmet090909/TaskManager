// Vraag 42: useful Qt class
// Waar: MainWindow erft van QMainWindow.

// Vraag 43: useful usage of signals/slots
// Waar: Qt slots on_*_clicked() worden gebruikt voor UI-interactie.


#pragma once

#include <QMainWindow>
#include "TaskManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace taskmgr::ui {

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void tasksChanged();

private:
    Ui::MainWindow *ui;
    taskmgr::TaskManager m_manager;

    void refreshTaskList();
    unsigned int currentSelectedTaskId() const;

private slots:
    void onTasksChanged();

    void on_addSimpleButton_clicked();
    void on_addTimedButton_clicked();
    void on_removeButton_clicked();
    void on_markDoneButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
};

} // namespace taskmgr::ui
