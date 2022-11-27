#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string>

void MainWindow::determineMap()
{
    QString source = "../images/qmap/qmap_";
    bool boolValues[3] = {ui->buildingsCheckBox->isChecked(), ui->fieldsCheckBox->isChecked(), ui->facilitiesCheckBox->isChecked()};
    for (int i = 0; i < 3; i++) {
//        qDebug() << boolValues[i];
        if (boolValues[i]) {
            source += "1";
        } else {
            source += "0";
        }
    }
    source += ".png";


    QImage newImage;
    newImage.load(source);
    ui->mapBackground->setPixmap(QPixmap::fromImage(newImage));
//    qDebug() << source;
}


void MainWindow::on_studentMapButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_zoomInButton_clicked()
{
//    ui->scrollAreaWidgetContents->setGeometry(0, 0, static_cast<int>(ui->scrollAreaWidgetContents->width()*1.1), static_cast<int>(ui->scrollAreaWidgetContents->height()*1.1));
    ui->mapBackground->setGeometry(0, 0, static_cast<int>(ui->mapBackground->width()*1.1), static_cast<int>(ui->mapBackground->height()*1.1));
//    qDebug() << static_cast<int>(ui->mapLayout->height());
}

void MainWindow::on_zoomOutButton_clicked()
{
    ui->mapBackground->setGeometry(0, 0, static_cast<int>(ui->mapBackground->width()/1.1), static_cast<int>(ui->mapBackground->height()/1.1));
//    qDebug() << static_cast<int>(ui->mapBackground->height());
}


void MainWindow::on_fieldsCheckBox_stateChanged(int arg1)
{
    determineMap();
}
