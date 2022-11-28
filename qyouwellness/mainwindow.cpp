#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QToolButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // create the button, make "this" the parent
//    m_button = new QPushButton("Take the survey", this);
//    // set size and location of the button
//    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200,50)));

//    // connect button signal to appropriate slot
//    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
    QPixmap pix_1("C:/Users/richa/Desktop/wellness_icons/wellnessicon-academic.png");
    ui->label_6->setPixmap(pix_1);

    QPixmap pix_2("C:/Users/richa/Desktop/wellness_icons/wellnessicon-mental.png");
    ui->label_8->setPixmap(pix_2);

    QPixmap pix_3("C:/Users/richa/Desktop/wellness_icons/wellnessicon-physical.png");
    ui->label_10->setPixmap(pix_3);

    QPixmap pix_4("C:/Users/richa/Desktop/wellness_icons/wellnessicon-financial.png");
    ui->label_12->setPixmap(pix_4);

//    QWidget *centralWidget = new QWidget(this);
//    QVBoxLayout *verticalLayout = new QVBoxLayout(centralWidget);
//    centralWidget->setLayout(verticalLayout);
//    setCentralWidget(centralWidget);

//    verticalLayout->addWidget(new QTableView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//CustomToolButton::CustomToolButton(QWidget *parent)
//     : QToolButton(parent)
//{
//    setPopupMode(QToolButton::MenuButtonPopup);
//    QObject::connect(this, SIGNAL(triggered(QAction*)),
//                     this, SLOT(setDefaultAction(QAction*)));
//}

//void MainWindow::on_pushButton_clicked()
//{
//    QMessageBox::information(this,"Title here","hello world");
//}

//void MainWindow::handleButton()
//{
//    // change the text
//    m_button->setText("Example");
//    // resize button
//    m_button->resize(100,100);
//}

void MainWindow::on_tabWidget_tabBarClicked(int)
{

}

