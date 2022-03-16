#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QMessageBox>
#include <QComboBox>
#include "prolib.h"
#include "keyHook.h"

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

    QLabel* staticLable_Times;
    QLabel* staticLable_Interval;
    QLabel* staticLable_Mode;

    QLineEdit* edit_Times;
    QLineEdit* edit_Interval;

    QComboBox* box_Mode;

    QPushButton* startButton;
    QPushButton* stopButton;

public slots:
    void startListening();
    void stopListening();
    void click();
};

#endif // MAINWINDOW_H
