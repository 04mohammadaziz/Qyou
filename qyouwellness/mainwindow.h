#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_tabWidget_tabBarClicked(int index);

    void on_dropdown_1_clicked();

    void on_dropdown_2_clicked();

    void on_physicalhealth_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};

//class CustomToolButton : public QToolButton
//{
//    Q_OBJECT

//public:
//    explicit CustomToolButton(QWidget *parent = 0);
//};

#endif // MAINWINDOW_H
