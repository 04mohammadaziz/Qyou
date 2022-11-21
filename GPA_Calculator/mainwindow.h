#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "Course.h"

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
	double getPointsFromGrade(std::string);
	
private slots:
	void on_pushButton_clicked();
	void on_CalculateGPA_clicked();
	void on_AddCourse_clicked();
	void on_DeleteCourse_clicked();
	void refresh();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
