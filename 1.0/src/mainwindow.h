#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>
#include <QComboBox>
#include <windows.h>
#include "prolib.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *Lable_static_x;
    QLabel *Lable_static_y;
    QLabel *Lable_static_Times;
    QLabel *Lable_static_Interval;
    QLabel *Lable_static_Mode;

    QLineEdit *Edit_Times;
    QLineEdit *Edit_Interval;

    QComboBox *Box_Mode;

    QPushButton *Button;

private slots:
    void on_Button_triggered();
};

#endif // MAINWINDOW_H
