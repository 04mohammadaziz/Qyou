#include "Error in " Util.relativeFilePath('C:/Users/cbyle/Desktop/Education/Queen's University/3-year/CMPE320/Project/main/team-26-nordic/mainwindow.h', 'C:/Users/cbyle/Desktop/Education/Queen's University/3-year/CMPE320/Project/main/team-26-nordic' + '/' + Util.path('mainwindow.cpp'))": SyntaxError: Expected token `)'"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

