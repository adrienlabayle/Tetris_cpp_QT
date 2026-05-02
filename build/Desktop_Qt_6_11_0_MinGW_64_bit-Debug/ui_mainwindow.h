/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Menu;
    QPushButton *play_button;
    QPushButton *settings_button;
    QPushButton *continue_button;
    QWidget *Tetris;
    QPushButton *quit_button;
    QPushButton *pause_button;
    QWidget *Pause;
    QPushButton *get_back_button;
    QPushButton *back_to_menu_button;
    QWidget *End;
    QPushButton *restart_button;
    QPushButton *back_to_menu_end_button;
    QWidget *Save;
    QPushButton *yes_button;
    QPushButton *no_button;
    QWidget *Difficulty;
    QPushButton *easy_button;
    QPushButton *medium_button;
    QPushButton *hard_button;
    QWidget *Settings;
    QPushButton *menu_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-20, -20, 800, 600));
        Menu = new QWidget();
        Menu->setObjectName("Menu");
        play_button = new QPushButton(Menu);
        play_button->setObjectName("play_button");
        play_button->setGeometry(QRect(70, 40, 130, 50));
        play_button->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"color : rgb(255, 234, 1);\n"
"font: 18pt \"Terminal\";"));
        play_button->setIconSize(QSize(12, 12));
        settings_button = new QPushButton(Menu);
        settings_button->setObjectName("settings_button");
        settings_button->setGeometry(QRect(70, 200, 130, 50));
        settings_button->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"color : rgb(255, 234, 1);\n"
"font: 18pt \"Terminal\";"));
        continue_button = new QPushButton(Menu);
        continue_button->setObjectName("continue_button");
        continue_button->setGeometry(QRect(70, 120, 130, 50));
        continue_button->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"color : rgb(255, 234, 1);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(Menu);
        Tetris = new QWidget();
        Tetris->setObjectName("Tetris");
        quit_button = new QPushButton(Tetris);
        quit_button->setObjectName("quit_button");
        quit_button->setGeometry(QRect(120, 430, 130, 50));
        quit_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        pause_button = new QPushButton(Tetris);
        pause_button->setObjectName("pause_button");
        pause_button->setGeometry(QRect(120, 360, 130, 50));
        pause_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(Tetris);
        Pause = new QWidget();
        Pause->setObjectName("Pause");
        get_back_button = new QPushButton(Pause);
        get_back_button->setObjectName("get_back_button");
        get_back_button->setGeometry(QRect(310, 180, 130, 50));
        get_back_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        back_to_menu_button = new QPushButton(Pause);
        back_to_menu_button->setObjectName("back_to_menu_button");
        back_to_menu_button->setGeometry(QRect(310, 300, 130, 50));
        back_to_menu_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(Pause);
        End = new QWidget();
        End->setObjectName("End");
        restart_button = new QPushButton(End);
        restart_button->setObjectName("restart_button");
        restart_button->setGeometry(QRect(160, 120, 130, 50));
        restart_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        back_to_menu_end_button = new QPushButton(End);
        back_to_menu_end_button->setObjectName("back_to_menu_end_button");
        back_to_menu_end_button->setGeometry(QRect(440, 120, 130, 50));
        back_to_menu_end_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(End);
        Save = new QWidget();
        Save->setObjectName("Save");
        yes_button = new QPushButton(Save);
        yes_button->setObjectName("yes_button");
        yes_button->setGeometry(QRect(230, 260, 130, 50));
        yes_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        no_button = new QPushButton(Save);
        no_button->setObjectName("no_button");
        no_button->setGeometry(QRect(450, 260, 130, 50));
        no_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(Save);
        Difficulty = new QWidget();
        Difficulty->setObjectName("Difficulty");
        easy_button = new QPushButton(Difficulty);
        easy_button->setObjectName("easy_button");
        easy_button->setGeometry(QRect(140, 220, 130, 50));
        easy_button->setStyleSheet(QString::fromUtf8("background-color : rgb(0, 170, 0);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        medium_button = new QPushButton(Difficulty);
        medium_button->setObjectName("medium_button");
        medium_button->setGeometry(QRect(320, 220, 130, 50));
        medium_button->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 85, 0);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        hard_button = new QPushButton(Difficulty);
        hard_button->setObjectName("hard_button");
        hard_button->setGeometry(QRect(500, 220, 130, 50));
        hard_button->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 0);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(Difficulty);
        Settings = new QWidget();
        Settings->setObjectName("Settings");
        menu_button = new QPushButton(Settings);
        menu_button->setObjectName("menu_button");
        menu_button->setGeometry(QRect(10, 20, 130, 50));
        menu_button->setStyleSheet(QString::fromUtf8("background-color : rgb(200, 123, 30);\n"
"color : rgb(0, 0, 127);\n"
"font: 18pt \"Terminal\";"));
        stackedWidget->addWidget(Settings);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        play_button->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        settings_button->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        continue_button->setText(QCoreApplication::translate("MainWindow", "Continue", nullptr));
        quit_button->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        pause_button->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        get_back_button->setText(QCoreApplication::translate("MainWindow", "Get back", nullptr));
        back_to_menu_button->setText(QCoreApplication::translate("MainWindow", "Back to menu", nullptr));
        restart_button->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        back_to_menu_end_button->setText(QCoreApplication::translate("MainWindow", "Back to menu", nullptr));
        yes_button->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        no_button->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        easy_button->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        medium_button->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        hard_button->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        menu_button->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
