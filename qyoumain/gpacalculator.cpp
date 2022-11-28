#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include <QTableWidget>

std::string pointToGrade(double grade){
  if (grade == 4.00)  return "A";
  else if (grade < 4.00 && grade >= 3.67 ) return "A-";
  else if (grade < 3.67 && grade >= 3.33)  return "B+";
  else if (grade < 3.33 && grade >= 2.67)  return "B" ;
  else if (grade < 2.67 && grade >= 2.33)  return "B-";
  else if (grade < 2.33 && grade >= 2.00)  return "C+";
  else if (grade < 2.00 && grade >= 1.00)  return "C" ;
  else if (grade < 1.00 && grade >= 0.00)  return "D" ;
  else return "F";
}

void MainWindow::on_CalculateGPA_clicked()
{
    double total_grade_points = 0;
    double total_credit = 0;
    double total_grade = 0;

    for(Course c: courses){
        total_credit += c.credit;
        total_grade_points  += c.getGradePoints();
        total_grade += c.getCreditPoint();
    }
    ui->average->setText(QString::fromStdString(pointToGrade(total_grade / courses.size())));
    ui->total->setText(QString::number(total_credit));

    ui->gpa->setText(QString::number(total_grade_points/total_grade));

}

void MainWindow::on_DeleteCourse_clicked()
{
    std::string name  = ui->newName->text().toStdString();
    courses.erase(std::remove_if(courses.begin(), courses.end(), [&name](auto& x) {return x.name == name;} ), courses.end());
    refresh();
}

void MainWindow::refresh(){

    ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());
    for (int i = 0; i < courses.size(); ++i ){

        ui->tableWidget->insertRow(i);


        QTableWidgetItem* item0 = new QTableWidgetItem(QString::fromStdString(courses.at(i).name));
        QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(courses.at(i).credit));
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(courses.at(i).grade));

        ui->tableWidget->setItem(i, 0, item0);
        ui->tableWidget->setItem(i, 1, item1);
        ui->tableWidget->setItem(i, 2, item2);
    }

}

void MainWindow::on_AddCourse_clicked()
{
    std::string name  = ui->newName->text().toStdString();
    int credit        = ui->newCredit->text().toInt();
    std::string grade = ui->newGrade->text().toStdString();

    if(credit <=0){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please enter valid credit and grade!");
        messageBox.setFixedSize(500,200);
    }
    else{
        bool found = false;
        for(Course c: courses){
            if(c.name == name){
                found = true;
                break;
            }
        }
        if(found){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Course with the name already exists! ");
            messageBox.setFixedSize(500,200);
        }else{
            courses.emplace_back(name, grade, credit);
            refresh();
        }
    }
}
