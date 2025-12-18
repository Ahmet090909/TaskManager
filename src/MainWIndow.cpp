// Vraag 8: fully working project
// Waar: alle UI-acties (add, remove, mark done, save, load) zijn volledig geïmplementeerd.

// Vraag 41: threads
// Waar: autosave thread wordt gestart in constructor en gestopt in destructor.

// Vraag 39: exception handling
// Waar: try/catch rond save/load in UI.

// Vraag 47: usage of a GUI
// Waar: volledige Qt GUI met formulieren, knoppen en lijstweergave.



#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SimpleTask.h"
#include "TimedTask.h"

#include <QMessageBox>
#include <QFileDialog>
#include <chrono>

namespace taskmgr::ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // start autosave thread (rubric threads)
    m_manager.startAutoSave("autosave_tasks.txt", std::chrono::seconds(15));

    refreshTaskList();
}

MainWindow::~MainWindow()
{
    m_manager.stopAutoSave();
    delete ui;
}

void MainWindow::refreshTaskList()
{
    ui->taskListWidget->clear();

    m_manager.forEachTask([this](const taskmgr::Task &t) {
        QString text;

        if (t.type() == TaskType::Simple) {
            text = QString("[Simple] #%1 (prio %2) %3%4 - %5")
                    .arg(t.id())
                    .arg(t.priority())
                    .arg(t.isDone() ? "[DONE] " : "")
                    .arg(QString::fromStdString(t.title()))
                    .arg(QString::fromStdString(t.description()));
        } else if (t.type() == TaskType::Timed) {
            auto const *timed = dynamic_cast<const TimedTask*>(&t);
            const QString due = timed ? QString::fromStdString(timed->dueDate()) : "n/a";

            text = QString("[Timed] #%1 (prio %2) %3%4 - %5 (due: %6)")
                    .arg(t.id())
                    .arg(t.priority())
                    .arg(t.isDone() ? "[DONE] " : "")
                    .arg(QString::fromStdString(t.title()))
                    .arg(QString::fromStdString(t.description()))
                    .arg(due);
        }

        auto *item = new QListWidgetItem(text, ui->taskListWidget);
        item->setData(Qt::UserRole, static_cast<uint>(t.id()));
    });
}

unsigned int MainWindow::currentSelectedTaskId() const
{
    auto *item = ui->taskListWidget->currentItem();
    if (!item) return 0;
    return item->data(Qt::UserRole).toUInt();
}

void MainWindow::on_addSimpleButton_clicked()
{
    const std::string title = ui->titleEdit->text().toStdString();
    const std::string desc  = ui->descriptionEdit->toPlainText().toStdString();
    const unsigned char prio = static_cast<unsigned char>(ui->prioritySpin->value());

    try {
        m_manager.addTask(new taskmgr::SimpleTask(title, desc, prio));
        refreshTaskList();
    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Error", ex.what());
    }
}

void MainWindow::on_addTimedButton_clicked()
{
    const std::string title = ui->titleEdit->text().toStdString();
    const std::string desc  = ui->descriptionEdit->toPlainText().toStdString();
    const unsigned char prio = static_cast<unsigned char>(ui->prioritySpin->value());
    const std::string due   = ui->dueDateEdit->text().toStdString();

    try {
        // ✅ juiste volgorde: (title, desc, priority, dueDate)
        m_manager.addTask(new taskmgr::TimedTask(title, desc, prio, due));
        refreshTaskList();
    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Error", ex.what());
    }
}

void MainWindow::on_removeButton_clicked()
{
    const unsigned int id = currentSelectedTaskId();
    if (id == 0) {
        QMessageBox::information(this, "Remove", "Selecteer eerst een taak.");
        return;
    }

    if (m_manager.removeTaskById(id)) {
        refreshTaskList();
    } else {
        QMessageBox::warning(this, "Remove", "Task niet gevonden.");
    }
}

void MainWindow::on_markDoneButton_clicked()
{
    const unsigned int id = currentSelectedTaskId();
    if (id == 0) {
        QMessageBox::information(this, "Mark done", "Selecteer eerst een taak.");
        return;
    }

    const bool ok = m_manager.editTaskById(id, [](taskmgr::Task& t) {
        t.setDone(true);
    });

    if (!ok) QMessageBox::warning(this, "Mark done", "Task niet gevonden.");
    refreshTaskList();
}

void MainWindow::on_saveButton_clicked()
{
    const QString fileName = QFileDialog::getSaveFileName(
                this, "Save tasks", QString(), "Text files (*.txt);;All files (*.*)");
    if (fileName.isEmpty()) return;

    try {
        m_manager.saveToFile(fileName.toStdString());
    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Save error", ex.what());
    }
}

void MainWindow::on_loadButton_clicked()
{
    const QString fileName = QFileDialog::getOpenFileName(
                this, "Load tasks", QString(), "Text files (*.txt);;All files (*.*)");
    if (fileName.isEmpty()) return;

    try {
        m_manager.loadFromFile(fileName.toStdString());
        refreshTaskList();
    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Load error", ex.what());
    }
}
void MainWindow::onTasksChanged()
{
    refreshTaskList();
}
} // namespace taskmgr::ui
