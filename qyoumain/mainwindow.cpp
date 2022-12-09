#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include <QUrl>
#include <QDesktopServices>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    courses = std::vector<Course>();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_studentMapButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_studentMapMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_GPACalculatorButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_gpaCalculatorMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_studentWellnessMenuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_studentWellnessButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_scheduleButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QDir::currentPath() + "/calendarbuild/qYouCalendar.exe"));
    this->close();
}


void MainWindow::on_toDoListButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QDir::currentPath() + "/todolistbuild/todo-list.exe"));
    this->close();
}

