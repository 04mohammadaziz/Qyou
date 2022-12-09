#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "course.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    std::vector<Course> courses;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Main Menu
    void on_GPACalculatorButton_clicked();
    void on_studentMapButton_clicked();

    // Map Feature
    void determineMap();
    void on_zoomOutButton_clicked();
    void on_zoomInButton_clicked();
    void on_buildingsCheckBox_clicked();
    void on_facilitiesCheckBox_clicked();
    void on_fieldsCheckBox_stateChanged(int arg1);

    // gpaCalculator
    void on_CalculateGPA_clicked();
    void on_AddCourse_clicked();
    void on_DeleteCourse_clicked();
    void refresh();



    void on_studentMapMenuButton_clicked();

    void on_gpaCalculatorMenuButton_clicked();

    void on_studentWellnessMenuButton_clicked();

    void on_studentWellnessButton_clicked();

    void on_scheduleButton_clicked();

    void on_toDoListButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
