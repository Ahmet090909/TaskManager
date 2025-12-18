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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QFrame *headerCard;
    QHBoxLayout *headerLayout;
    QLabel *appTitle;
    QSpacerItem *headerSpacer;
    QLabel *hintLabel;
    QSplitter *splitter;
    QWidget *leftPane;
    QVBoxLayout *leftLayout;
    QGroupBox *tasksGroup;
    QVBoxLayout *tasksLayout;
    QLineEdit *searchEdit;
    QListWidget *taskListWidget;
    QHBoxLayout *tasksBottomRow;
    QCheckBox *showDoneCheck;
    QSpacerItem *tasksBottomSpacer;
    QWidget *rightPane;
    QVBoxLayout *rightLayout;
    QGroupBox *createGroup;
    QFormLayout *formLayout;
    QLabel *labelTitle;
    QLineEdit *titleEdit;
    QLabel *labelDesc;
    QTextEdit *descriptionEdit;
    QLabel *labelPrio;
    QSpinBox *prioritySpin;
    QLabel *labelDue;
    QLineEdit *dueDateEdit;
    QGroupBox *actionsGroup;
    QGridLayout *actionsGrid;
    QPushButton *addSimpleButton;
    QPushButton *addTimedButton;
    QPushButton *markDoneButton;
    QPushButton *removeButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QSpacerItem *rightSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 640);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow, QWidget {\n"
"  background: #0f172a;\n"
"  color: #e5e7eb;\n"
"  font-size: 13px;\n"
"}\n"
"\n"
"QGroupBox {\n"
"  border: 1px solid #243044;\n"
"  border-radius: 10px;\n"
"  margin-top: 14px;\n"
"  padding: 10px;\n"
"  background: #111c33;\n"
"}\n"
"QGroupBox::title {\n"
"  subcontrol-origin: margin;\n"
"  subcontrol-position: top left;\n"
"  padding: 0 8px;\n"
"  color: #cbd5e1;\n"
"  font-weight: 600;\n"
"}\n"
"\n"
"QLineEdit, QTextEdit, QSpinBox, QListWidget {\n"
"  background: #0b1222;\n"
"  border: 1px solid #25314a;\n"
"  border-radius: 10px;\n"
"  padding: 10px;\n"
"  selection-background-color: #2563eb;\n"
"}\n"
"QTextEdit { padding: 10px; }\n"
"QSpinBox { padding-right: 30px; }\n"
"\n"
"QListWidget::item {\n"
"  padding: 8px;\n"
"  border-radius: 8px;\n"
"}\n"
"QListWidget::item:selected {\n"
"  background: #1d4ed8;\n"
"  color: #ffffff;\n"
"}\n"
"\n"
"QPushButton {\n"
"  border: 1px solid #2b3a57;\n"
"  border-radius: 10px;\n"
"  padding: 10px 14px;\n"
"  background: #0b1222;\n"
"}"
                        "\n"
"QPushButton:hover { background: #111c33; }\n"
"QPushButton:pressed { background: #0a1020; }\n"
"\n"
"QPushButton#addSimpleButton { background: #0b3b8a; border-color: #1d4ed8; }\n"
"QPushButton#addTimedButton  { background: #0b3b8a; border-color: #1d4ed8; }\n"
"QPushButton#markDoneButton  { background: #065f46; border-color: #10b981; }\n"
"QPushButton#removeButton    { background: #7f1d1d; border-color: #ef4444; }\n"
"QPushButton#saveButton      { background: #334155; border-color: #475569; }\n"
"QPushButton#loadButton      { background: #334155; border-color: #475569; }\n"
"\n"
"QLabel {\n"
"  color: #cbd5e1;\n"
"}\n"
"\n"
"QCheckBox { spacing: 8px; }\n"
"QCheckBox::indicator {\n"
"  width: 16px; height: 16px;\n"
"}\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setSpacing(12);
        rootLayout->setObjectName("rootLayout");
        rootLayout->setContentsMargins(14, 14, 14, 14);
        headerCard = new QFrame(centralwidget);
        headerCard->setObjectName("headerCard");
        headerCard->setStyleSheet(QString::fromUtf8("\n"
"QFrame#headerCard {\n"
"  background: #111c33;\n"
"  border: 1px solid #243044;\n"
"  border-radius: 12px;\n"
"}\n"
"       "));
        headerLayout = new QHBoxLayout(headerCard);
        headerLayout->setObjectName("headerLayout");
        headerLayout->setContentsMargins(14, 12, 14, 12);
        appTitle = new QLabel(headerCard);
        appTitle->setObjectName("appTitle");
        appTitle->setStyleSheet(QString::fromUtf8("\n"
"QLabel#appTitle { font-size: 18px; font-weight: 700; color: #ffffff; }\n"
"          "));

        headerLayout->addWidget(appTitle);

        headerSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        headerLayout->addItem(headerSpacer);

        hintLabel = new QLabel(headerCard);
        hintLabel->setObjectName("hintLabel");
        hintLabel->setStyleSheet(QString::fromUtf8("\n"
"QLabel#hintLabel { color: #94a3b8; }\n"
"          "));

        headerLayout->addWidget(hintLabel);


        rootLayout->addWidget(headerCard);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        leftPane = new QWidget(splitter);
        leftPane->setObjectName("leftPane");
        leftLayout = new QVBoxLayout(leftPane);
        leftLayout->setSpacing(10);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(0, 0, 0, 0);
        tasksGroup = new QGroupBox(leftPane);
        tasksGroup->setObjectName("tasksGroup");
        tasksLayout = new QVBoxLayout(tasksGroup);
        tasksLayout->setSpacing(10);
        tasksLayout->setObjectName("tasksLayout");
        searchEdit = new QLineEdit(tasksGroup);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setClearButtonEnabled(true);

        tasksLayout->addWidget(searchEdit);

        taskListWidget = new QListWidget(tasksGroup);
        taskListWidget->setObjectName("taskListWidget");
        taskListWidget->setMinimumWidth(360);
        taskListWidget->setAlternatingRowColors(true);
        taskListWidget->setSelectionMode(QAbstractItemView::SingleSelection);

        tasksLayout->addWidget(taskListWidget);

        tasksBottomRow = new QHBoxLayout();
        tasksBottomRow->setObjectName("tasksBottomRow");
        showDoneCheck = new QCheckBox(tasksGroup);
        showDoneCheck->setObjectName("showDoneCheck");
        showDoneCheck->setChecked(true);

        tasksBottomRow->addWidget(showDoneCheck);

        tasksBottomSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        tasksBottomRow->addItem(tasksBottomSpacer);


        tasksLayout->addLayout(tasksBottomRow);


        leftLayout->addWidget(tasksGroup);

        splitter->addWidget(leftPane);
        rightPane = new QWidget(splitter);
        rightPane->setObjectName("rightPane");
        rightLayout = new QVBoxLayout(rightPane);
        rightLayout->setSpacing(12);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, 0, 0);
        createGroup = new QGroupBox(rightPane);
        createGroup->setObjectName("createGroup");
        formLayout = new QFormLayout(createGroup);
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(12);
        formLayout->setVerticalSpacing(12);
        labelTitle = new QLabel(createGroup);
        labelTitle->setObjectName("labelTitle");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelTitle);

        titleEdit = new QLineEdit(createGroup);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setClearButtonEnabled(true);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, titleEdit);

        labelDesc = new QLabel(createGroup);
        labelDesc->setObjectName("labelDesc");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelDesc);

        descriptionEdit = new QTextEdit(createGroup);
        descriptionEdit->setObjectName("descriptionEdit");
        descriptionEdit->setMinimumHeight(170);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, descriptionEdit);

        labelPrio = new QLabel(createGroup);
        labelPrio->setObjectName("labelPrio");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelPrio);

        prioritySpin = new QSpinBox(createGroup);
        prioritySpin->setObjectName("prioritySpin");
        prioritySpin->setMinimum(0);
        prioritySpin->setMaximum(10);
        prioritySpin->setValue(5);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, prioritySpin);

        labelDue = new QLabel(createGroup);
        labelDue->setObjectName("labelDue");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelDue);

        dueDateEdit = new QLineEdit(createGroup);
        dueDateEdit->setObjectName("dueDateEdit");
        dueDateEdit->setClearButtonEnabled(true);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, dueDateEdit);


        rightLayout->addWidget(createGroup);

        actionsGroup = new QGroupBox(rightPane);
        actionsGroup->setObjectName("actionsGroup");
        actionsGrid = new QGridLayout(actionsGroup);
        actionsGrid->setObjectName("actionsGrid");
        actionsGrid->setHorizontalSpacing(12);
        actionsGrid->setVerticalSpacing(12);
        addSimpleButton = new QPushButton(actionsGroup);
        addSimpleButton->setObjectName("addSimpleButton");
        addSimpleButton->setMinimumHeight(42);

        actionsGrid->addWidget(addSimpleButton, 0, 0, 1, 1);

        addTimedButton = new QPushButton(actionsGroup);
        addTimedButton->setObjectName("addTimedButton");
        addTimedButton->setMinimumHeight(42);

        actionsGrid->addWidget(addTimedButton, 0, 1, 1, 1);

        markDoneButton = new QPushButton(actionsGroup);
        markDoneButton->setObjectName("markDoneButton");
        markDoneButton->setMinimumHeight(42);

        actionsGrid->addWidget(markDoneButton, 1, 0, 1, 1);

        removeButton = new QPushButton(actionsGroup);
        removeButton->setObjectName("removeButton");
        removeButton->setMinimumHeight(42);

        actionsGrid->addWidget(removeButton, 1, 1, 1, 1);

        saveButton = new QPushButton(actionsGroup);
        saveButton->setObjectName("saveButton");
        saveButton->setMinimumHeight(42);

        actionsGrid->addWidget(saveButton, 2, 0, 1, 1);

        loadButton = new QPushButton(actionsGroup);
        loadButton->setObjectName("loadButton");
        loadButton->setMinimumHeight(42);

        actionsGrid->addWidget(loadButton, 2, 1, 1, 1);


        rightLayout->addWidget(actionsGroup);

        rightSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightLayout->addItem(rightSpacer);

        splitter->addWidget(rightPane);

        rootLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Taakbeheer", nullptr));
        appTitle->setText(QCoreApplication::translate("MainWindow", "Taakbeheer", nullptr));
        tasksGroup->setTitle(QCoreApplication::translate("MainWindow", "Takenlijst", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Zoeken\342\200\246", nullptr));
        showDoneCheck->setText(QCoreApplication::translate("MainWindow", "Toon klaar", nullptr));
        createGroup->setTitle(QCoreApplication::translate("MainWindow", "Nieuwe taak", nullptr));
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Titel", nullptr));
        titleEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Bijv. \342\200\234Verslag afwerken\342\200\235", nullptr));
        labelDesc->setText(QCoreApplication::translate("MainWindow", "Beschrijving", nullptr));
        descriptionEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Wat moet er precies gebeuren?", nullptr));
        labelPrio->setText(QCoreApplication::translate("MainWindow", "Prioriteit", nullptr));
        labelDue->setText(QCoreApplication::translate("MainWindow", "Vervaldatum", nullptr));
        dueDateEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "YYYY-MM-DD HH:MM (alleen timed)", nullptr));
        actionsGroup->setTitle(QCoreApplication::translate("MainWindow", "Acties", nullptr));
        addSimpleButton->setText(QCoreApplication::translate("MainWindow", "Voeg simpele taak toe", nullptr));
        addTimedButton->setText(QCoreApplication::translate("MainWindow", "Voeg timed taak toe", nullptr));
        markDoneButton->setText(QCoreApplication::translate("MainWindow", "Markeer klaar", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Verwijderen", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Opslaan", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Laden", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
