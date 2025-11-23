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
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    taskmgr::TaskManager m_manager;  // UI heeft een TaskManager (compositie)

    void refreshTaskList();
    unsigned int currentSelectedTaskId() const;

private slots:
    void on_addSimpleButton_clicked();
    void on_addTimedButton_clicked();
    void on_removeButton_clicked();
    void on_markDoneButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
};

} // namespace taskmgr::ui
