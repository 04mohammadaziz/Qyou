/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *scheduleButton;
    QPushButton *toDoButton;
    QPushButton *studentMapButton;
    QPushButton *gpaButton_4;
    QPushButton *studentWellnessButton_5;
    QLabel *logo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(854, 553);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"background-color: qlineargradient(spread:pad, x1:0.2, y1:0.3, x2:0.7, y2:1.2, stop:0 rgba(0, 36, 82, 255), stop:1 rgba(0, 56, 110, 255))\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        scheduleButton = new QPushButton(centralwidget);
        scheduleButton->setObjectName("scheduleButton");
        scheduleButton->setGeometry(QRect(550, 30, 251, 81));
        scheduleButton->setMinimumSize(QSize(251, 0));
        scheduleButton->setMaximumSize(QSize(16777215, 81));
        scheduleButton->setAutoFillBackground(false);
        scheduleButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 28pt \"Quicksand Medium\";\n"
"	font: 22pt \"Quicksand\";\n"
"color: #000000;\n"
"border: 2px solid #555;\n"
"border-radius: 20px;\n"
"border-style: outset;\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #DDD\n"
");\n"
"padding: 10px;\n"
"}"));
        scheduleButton->setCheckable(false);
        toDoButton = new QPushButton(centralwidget);
        toDoButton->setObjectName("toDoButton");
        toDoButton->setGeometry(QRect(550, 130, 251, 81));
        toDoButton->setMinimumSize(QSize(251, 0));
        toDoButton->setMaximumSize(QSize(16777215, 81));
        toDoButton->setAutoFillBackground(false);
        toDoButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 28pt \"Quicksand Medium\";\n"
"	font: 22pt \"Quicksand\";\n"
"color: #000000;\n"
"border: 2px solid #555;\n"
"border-radius: 20px;\n"
"border-style: outset;\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #DDD\n"
");\n"
"padding: 10px;\n"
"}"));
        toDoButton->setCheckable(false);
        studentMapButton = new QPushButton(centralwidget);
        studentMapButton->setObjectName("studentMapButton");
        studentMapButton->setGeometry(QRect(550, 230, 251, 81));
        studentMapButton->setMinimumSize(QSize(251, 0));
        studentMapButton->setMaximumSize(QSize(16777215, 81));
        studentMapButton->setAutoFillBackground(false);
        studentMapButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 28pt \"Quicksand Medium\";\n"
"	font: 22pt \"Quicksand\";\n"
"color: #000000;\n"
"border: 2px solid #555;\n"
"border-radius: 20px;\n"
"border-style: outset;\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #DDD\n"
");\n"
"padding: 10px;\n"
"}"));
        studentMapButton->setCheckable(false);
        gpaButton_4 = new QPushButton(centralwidget);
        gpaButton_4->setObjectName("gpaButton_4");
        gpaButton_4->setGeometry(QRect(550, 330, 251, 81));
        gpaButton_4->setMinimumSize(QSize(251, 0));
        gpaButton_4->setMaximumSize(QSize(16777215, 81));
        gpaButton_4->setAutoFillBackground(false);
        gpaButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 28pt \"Quicksand Medium\";\n"
"	font: 22pt \"Quicksand\";\n"
"color: #000000;\n"
"border: 2px solid #555;\n"
"border-radius: 20px;\n"
"border-style: outset;\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #DDD\n"
");\n"
"padding: 10px;\n"
"}"));
        gpaButton_4->setCheckable(false);
        studentWellnessButton_5 = new QPushButton(centralwidget);
        studentWellnessButton_5->setObjectName("studentWellnessButton_5");
        studentWellnessButton_5->setGeometry(QRect(550, 430, 251, 81));
        studentWellnessButton_5->setMinimumSize(QSize(251, 0));
        studentWellnessButton_5->setMaximumSize(QSize(16777215, 81));
        studentWellnessButton_5->setAutoFillBackground(false);
        studentWellnessButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 500 28pt \"Quicksand Medium\";\n"
"	font: 22pt \"Quicksand\";\n"
"color: #000000;\n"
"border: 2px solid #555;\n"
"border-radius: 20px;\n"
"border-style: outset;\n"
"background: qradialgradient(\n"
"cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4,\n"
"radius: 1.35, stop: 0 #fff, stop: 1 #DDD\n"
");\n"
"padding: 10px;\n"
"}"));
        studentWellnessButton_5->setCheckable(false);
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(-10, -20, 571, 551));
        logo->setPixmap(QPixmap(QString::fromUtf8("../images/Logo v1-midgreyline.png")));
        logo->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        scheduleButton->setText(QCoreApplication::translate("MainWindow", "Schedule", nullptr));
        toDoButton->setText(QCoreApplication::translate("MainWindow", "To Do List", nullptr));
        studentMapButton->setText(QCoreApplication::translate("MainWindow", "Student Map", nullptr));
        gpaButton_4->setText(QCoreApplication::translate("MainWindow", "GPA Calculator", nullptr));
        studentWellnessButton_5->setText(QCoreApplication::translate("MainWindow", "Student Wellness", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
