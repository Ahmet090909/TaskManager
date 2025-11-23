#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SimpleTask.h"
#include "TimedTask.h"

#include <QMessageBox>
#include <QFileDialog>

namespace taskmgr::ui {

    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
    {
        ui->setupUi(this);

        // init priority spin
        ui->prioritySpin->setMinimum(0);
        ui->prioritySpin->setMaximum(10);
        ui->prioritySpin->setValue(5);

        refreshTaskList();
    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }

    void MainWindow::refreshTaskList()
    {
        ui->taskListWidget->clear();

        m_manager.forEachTask([this](const Task &t) {
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
                QString due = timed ? QString::fromStdString(timed->dueDate()) : "n/a";
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
        std::string title = ui->titleEdit->text().toStdString();
        std::string desc  = ui->descriptionEdit->toPlainText().toStdString();
        unsigned char prio = static_cast<unsigned char>(ui->prioritySpin->value());

        try {
            m_manager.addTask(new SimpleTask(title, desc, prio));
            refreshTaskList();
        } catch (const std::exception &ex) {
            QMessageBox::critical(this, "Error", ex.what());
        }
    }

    void MainWindow::on_addTimedButton_clicked()
    {
        std::string title = ui->titleEdit->text().toStdString();
        std::string desc  = ui->descriptionEdit->toPlainText().toStdString();
        unsigned char prio = static_cast<unsigned char>(ui->prioritySpin->value());
        std::string due   = ui->dueDateEdit->text().toStdString();

        try {
            m_manager.addTask(new TimedTask(title, desc, prio, due));
            refreshTaskList();
        } catch (const std::exception &ex) {
            QMessageBox::critical(this, "Error", ex.what());
        }
    }

    void MainWindow::on_removeButton_clicked()
    {
        unsigned int id = currentSelectedTaskId();
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
        unsigned int id = currentSelectedTaskId();
        if (id == 0) {
            QMessageBox::information(this, "Mark done", "Selecteer eerst een taak.");
            return;
        }

        Task *t = m_manager.findTaskById(id);
        if (!t) {
            QMessageBox::warning(this, "Mark done", "Task niet gevonden.");
            return;
        }

        t->setDone(true);
        refreshTaskList();
    }

    void MainWindow::on_saveButton_clicked()
    {
        QString fileName = QFileDialog::getSaveFileName(
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
        QString fileName = QFileDialog::getOpenFileName(
                    this, "Load tasks", QString(), "Text files (*.txt);;All files (*.*)");
        if (fileName.isEmpty()) return;

        try {
            m_manager.loadFromFile(fileName.toStdString());
            refreshTaskList();
        } catch (const std::exception &ex) {
            QMessageBox::critical(this, "Load error", ex.what());
        }
    }

} // namespace taskmgr::ui
