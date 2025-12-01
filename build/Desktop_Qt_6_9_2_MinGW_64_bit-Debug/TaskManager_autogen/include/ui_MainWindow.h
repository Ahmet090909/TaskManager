/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_main;
    QListWidget *taskListWidget;
    QWidget *rightPanel;
    QVBoxLayout *verticalLayout_right;
    QLabel *labelTitle;
    QLineEdit *titleEdit;
    QLabel *labelDescription;
    QTextEdit *descriptionEdit;
    QLabel *labelPriority;
    QSpinBox *prioritySpin;
    QLabel *labelDueDate;
    QLineEdit *dueDateEdit;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *addSimpleButton;
    QPushButton *addTimedButton;
    QPushButton *removeButton;
    QPushButton *markDoneButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow {\n"
"    background-color: #1e1e1e;\n"
"    color: #f0f0f0;\n"
"}\n"
"\n"
"/* Links: lijst met taken */\n"
"QListWidget#taskListWidget {\n"
"    background-color: #252526;\n"
"    color: #f0f0f0;\n"
"    border: 1px solid #3c3c3c;\n"
"    border-radius: 6px;\n"
"    padding: 4px;\n"
"}\n"
"QListWidget#taskListWidget::item {\n"
"    padding: 4px 6px;\n"
"}\n"
"QListWidget#taskListWidget::item:selected {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Labels */\n"
"QLabel {\n"
"    color: #f0f0f0;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"/* Invoervelden rechts */\n"
"QLineEdit, QTextEdit, QSpinBox {\n"
"    background-color: #2d2d30;\n"
"    color: #f0f0f0;\n"
"    border: 1px solid #3c3c3c;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}\n"
"QTextEdit {\n"
"    min-height: 80px;\n"
"}\n"
"\n"
"/* Knoppen algemeen */\n"
"QPushButton {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"    border:"
                        " none;\n"
"    font-weight: 500;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #1890ff;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #005a9e;\n"
"}\n"
"\n"
"/* Specifieke knoppen met eigen kleur */\n"
"QPushButton#removeButton {\n"
"    background-color: #d83b01;\n"
"}\n"
"QPushButton#removeButton:hover {\n"
"    background-color: #f7630c;\n"
"}\n"
"\n"
"QPushButton#markDoneButton {\n"
"    background-color: #107c10;\n"
"}\n"
"QPushButton#markDoneButton:hover {\n"
"    background-color: #16a316;\n"
"}\n"
"\n"
"QPushButton#saveButton {\n"
"    background-color: #605e5c;\n"
"}\n"
"QPushButton#saveButton:hover {\n"
"    background-color: #7a7574;\n"
"}\n"
"\n"
"QPushButton#loadButton {\n"
"    background-color: #2b88d8;\n"
"}\n"
"QPushButton#loadButton:hover {\n"
"    background-color: #3aa0ff;\n"
"}\n"
"\n"
"/* Menubalk en statusbalk */\n"
"QMenuBar {\n"
"    background-color: #2d2d30;\n"
"    color: #f0f0f0;\n"
"}\n"
"QStatusBar {\n"
"    background-color: #2d2d30;\n"
"    color: #f0f0f0;"
                        "\n"
"}\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_main = new QHBoxLayout(centralwidget);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        taskListWidget = new QListWidget(centralwidget);
        taskListWidget->setObjectName("taskListWidget");

        horizontalLayout_main->addWidget(taskListWidget);

        rightPanel = new QWidget(centralwidget);
        rightPanel->setObjectName("rightPanel");
        verticalLayout_right = new QVBoxLayout(rightPanel);
        verticalLayout_right->setObjectName("verticalLayout_right");
        labelTitle = new QLabel(rightPanel);
        labelTitle->setObjectName("labelTitle");

        verticalLayout_right->addWidget(labelTitle);

        titleEdit = new QLineEdit(rightPanel);
        titleEdit->setObjectName("titleEdit");

        verticalLayout_right->addWidget(titleEdit);

        labelDescription = new QLabel(rightPanel);
        labelDescription->setObjectName("labelDescription");

        verticalLayout_right->addWidget(labelDescription);

        descriptionEdit = new QTextEdit(rightPanel);
        descriptionEdit->setObjectName("descriptionEdit");

        verticalLayout_right->addWidget(descriptionEdit);

        labelPriority = new QLabel(rightPanel);
        labelPriority->setObjectName("labelPriority");

        verticalLayout_right->addWidget(labelPriority);

        prioritySpin = new QSpinBox(rightPanel);
        prioritySpin->setObjectName("prioritySpin");
        prioritySpin->setMinimum(0);
        prioritySpin->setMaximum(10);
        prioritySpin->setValue(5);

        verticalLayout_right->addWidget(prioritySpin);

        labelDueDate = new QLabel(rightPanel);
        labelDueDate->setObjectName("labelDueDate");

        verticalLayout_right->addWidget(labelDueDate);

        dueDateEdit = new QLineEdit(rightPanel);
        dueDateEdit->setObjectName("dueDateEdit");

        verticalLayout_right->addWidget(dueDateEdit);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        addSimpleButton = new QPushButton(rightPanel);
        addSimpleButton->setObjectName("addSimpleButton");

        horizontalLayout_buttons->addWidget(addSimpleButton);

        addTimedButton = new QPushButton(rightPanel);
        addTimedButton->setObjectName("addTimedButton");

        horizontalLayout_buttons->addWidget(addTimedButton);

        removeButton = new QPushButton(rightPanel);
        removeButton->setObjectName("removeButton");

        horizontalLayout_buttons->addWidget(removeButton);

        markDoneButton = new QPushButton(rightPanel);
        markDoneButton->setObjectName("markDoneButton");

        horizontalLayout_buttons->addWidget(markDoneButton);

        saveButton = new QPushButton(rightPanel);
        saveButton->setObjectName("saveButton");

        horizontalLayout_buttons->addWidget(saveButton);

        loadButton = new QPushButton(rightPanel);
        loadButton->setObjectName("loadButton");

        horizontalLayout_buttons->addWidget(loadButton);


        verticalLayout_right->addLayout(horizontalLayout_buttons);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_right->addItem(verticalSpacer);


        horizontalLayout_main->addWidget(rightPanel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Taakbeheer", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Titel", nullptr));
        labelDescription->setText(QCoreApplication::translate("MainWindow", "Beschrijving", nullptr));
        labelPriority->setText(QCoreApplication::translate("MainWindow", "Prioriteit (0-10)", nullptr));
        labelDueDate->setText(QCoreApplication::translate("MainWindow", "Vervaldatum (JJJJ-MM-DD UU:MM)", nullptr));
        addSimpleButton->setText(QCoreApplication::translate("MainWindow", "Voeg simpele taak toe", nullptr));
        addTimedButton->setText(QCoreApplication::translate("MainWindow", "Voeg timed taak toe", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Verwijderen", nullptr));
        markDoneButton->setText(QCoreApplication::translate("MainWindow", "Markeer klaar", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Opslaan", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Laden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
