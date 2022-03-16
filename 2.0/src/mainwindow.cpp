#include "mainwindow.h"
#include "ui_mainwindow.h"

extern KeyHook* keyHook;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(400, 300);
    setWindowTitle("Cliker-2.0");

    staticLable_Times = new QLabel(this);
    staticLable_Times ->setGeometry(25, 55, 100, 30);
    staticLable_Times ->setFont(QFont("Timers", 15, QFont::Bold));
    staticLable_Times ->setAlignment(Qt::AlignRight);
    staticLable_Times ->setText("次数:");

    staticLable_Interval = new QLabel(this);
    staticLable_Interval ->setGeometry(25, 105, 100, 30);
    staticLable_Interval ->setFont(QFont("Timers", 15, QFont::Bold));
    staticLable_Interval ->setAlignment(Qt::AlignRight);
    staticLable_Interval ->setText("间隔:");

    staticLable_Mode = new QLabel(this);
    staticLable_Mode ->setGeometry(25, 155, 100, 30);
    staticLable_Mode ->setFont(QFont("Timers", 15, QFont::Bold));
    staticLable_Mode ->setAlignment(Qt::AlignRight);
    staticLable_Mode ->setText("模式:");

    edit_Times = new QLineEdit(this);
    edit_Times ->setGeometry(150, 50, 100, 40);
    edit_Times ->setFont(QFont("Timers", 15, QFont::Bold));
    edit_Times ->setText(QString::number(-1));

    edit_Interval = new QLineEdit(this);
    edit_Interval ->setGeometry(150, 100, 100, 40);
    edit_Interval ->setFont(QFont("Timers", 15, QFont::Bold));
    edit_Interval ->setText(QString::number(30));

    box_Mode = new QComboBox(this);
    box_Mode ->setGeometry(150, 150, 150, 40);
    box_Mode ->setFont(QFont("Timers", 15, QFont::Bold));
    box_Mode ->addItems(QStringList() << "左键" << "右键");

    startButton = new QPushButton(this);
    startButton ->setGeometry(30, 220, 150, 50);
    startButton ->setFont(QFont("Timers", 15, QFont::Bold));
    startButton ->setText("开始监听");

    stopButton = new QPushButton(this);
    stopButton ->setGeometry(220, 220, 150, 50);
    stopButton ->setFont(QFont("Timers", 15, QFont::Bold));
    stopButton ->setText("停止监听");

    QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(startListening()));
    QObject::connect(stopButton, SIGNAL(clicked()), this, SLOT(stopListening()));
    QObject::connect(keyHook, SIGNAL(keyDown()), this, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startListening()
{
    setKeyHook();
}

void MainWindow::stopListening()
{
    unloadKeyHook();
}

void MainWindow::click()
{
    int x = QCursor::pos().x();
    int y = QCursor::pos().y();

    int times = edit_Times ->text().toInt();
    int interval = edit_Interval ->text().toInt();

    if(notIn(x, 0, GetSystemMetrics(SM_CXSCREEN)) || notIn(y, 0, GetSystemMetrics(SM_CYSCREEN)) || times < -1 || interval < 10)
    {
        QMessageBox::warning(nullptr, "输入错误", "请输入正确数值!(点击间隔不得小于10ms)");
        return;
    }

    QCursor::setPos(x, y);
    Sleep(20);

    DWORD dword_DOWN, dword_UP;
    switch(box_Mode ->currentIndex())
    {
    case 0:
    {
        dword_DOWN = MOUSEEVENTF_LEFTDOWN;
        dword_UP = MOUSEEVENTF_LEFTUP;
        break;
    }
    case 1:
    {
        dword_DOWN = MOUSEEVENTF_RIGHTDOWN;
        dword_UP = MOUSEEVENTF_RIGHTUP;
        break;
    }
    default:
    {
        return;
    }
    }

    for(int i = 0; times == -1 || i < times; ++i)
    {
        ::mouse_event(dword_DOWN, 0, 0, 0, 0);
        Sleep(10);
        ::mouse_event(dword_UP, 0, 0, 0, 0);
        Sleep(interval - 10);

        if(QCursor::pos().x() != x || QCursor::pos().y() != y)
        {
            break;
        }
    }
}


