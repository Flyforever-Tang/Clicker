#include "mainwindow.h"
#include "ui_mainwindow.h"

static QLineEdit *Edit_x, *Edit_y;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(400, 300);
    setWindowTitle("Cliker");

    Lable_static_x = new QLabel(this);
    Lable_static_x ->setGeometry(20, 50, 30, 30);
    Lable_static_x ->setFont(QFont("Timers", 15, QFont::Bold));
    Lable_static_x ->setAlignment(Qt::AlignRight);
    Lable_static_x ->setText("x:");

    Lable_static_y = new QLabel(this);
    Lable_static_y ->setGeometry(20, 100, 30, 30);
    Lable_static_y ->setFont(QFont("Timers", 15, QFont::Bold));
    Lable_static_y ->setAlignment(Qt::AlignRight);
    Lable_static_y ->setText("y:");

    Lable_static_Times = new QLabel(this);
    Lable_static_Times ->setGeometry(130, 50, 150, 30);
    Lable_static_Times ->setFont(QFont("Timers", 15, QFont::Bold));
    Lable_static_Times ->setAlignment(Qt::AlignRight);
    Lable_static_Times ->setText("Times:");

    Lable_static_Interval = new QLabel(this);
    Lable_static_Interval ->setGeometry(130, 100, 150, 30);
    Lable_static_Interval ->setFont(QFont("Timers", 15, QFont::Bold));
    Lable_static_Interval ->setAlignment(Qt::AlignRight);
    Lable_static_Interval ->setText("Interval:");

    Lable_static_Mode = new QLabel(this);
    Lable_static_Mode ->setGeometry(50, 150, 80, 30);
    Lable_static_Mode ->setFont(QFont("Timers", 15, QFont::Bold));
    Lable_static_Mode ->setAlignment(Qt::AlignRight);
    Lable_static_Mode ->setText("Mode:");

    Edit_x = new QLineEdit(this);
    Edit_x ->setGeometry(50, 50, 80, 30);
    Edit_x ->setFont(QFont("Timers", 15, QFont::Bold));
    Edit_x ->setText(QString::number(QCursor::pos().x()));

    Edit_y = new QLineEdit(this);
    Edit_y ->setGeometry(50, 100, 80, 30);
    Edit_y ->setFont(QFont("Timers", 15, QFont::Bold));
    Edit_y ->setText(QString::number(QCursor::pos().y()));

    Edit_Times = new QLineEdit(this);
    Edit_Times ->setGeometry(280, 50, 100, 30);
    Edit_Times ->setFont(QFont("Timers", 15, QFont::Bold));
    Edit_Times ->setText(QString::number(100));

    Edit_Interval = new QLineEdit(this);
    Edit_Interval ->setGeometry(280, 100, 100, 30);
    Edit_Interval ->setFont(QFont("Timers", 15, QFont::Bold));
    Edit_Interval ->setText(QString::number(30));

    Box_Mode = new QComboBox(this);
    Box_Mode ->setGeometry(130, 150, 200, 30);
    Box_Mode ->setFont(QFont("Timers", 15, QFont::Bold));
    Box_Mode ->addItems(QStringList() << "Left Click" << "Right Click");

    Button = new QPushButton(this);
    Button ->setGeometry(100, 200, 200, 80);
    Button ->setFont(QFont("Timers", 25, QFont::Bold));
    Button ->setText("Start");
    QObject::connect(Button, SIGNAL(clicked()), this, SLOT(on_Button_triggered()));
}

void QWidget::mouseMoveEvent(QMouseEvent *event)
{
    event->globalPos();
    event->globalX();
    event->globalY();

    Edit_x ->setText(QString::number(QCursor::pos().x()));
    Edit_y ->setText(QString::number(QCursor::pos().y()));
}

void MainWindow::on_Button_triggered()
{
    int x = Edit_x ->text().toInt(), y = Edit_y ->text().toInt(), Times = Edit_Times ->text().toInt(), Interval = Edit_Interval ->text().toInt();

    if(notIn(x, 0, GetSystemMetrics(SM_CXSCREEN)) || notIn(y, 0, GetSystemMetrics(SM_CYSCREEN)) || Times < -1 || Interval < 20)
    {
        QMessageBox::warning(nullptr, "Wrong Input", "Please Set Correct Input!");
        return;
    }

    QCursor::setPos(x, y);
    Sleep(20);

    for(int i = 0; i < Times || Times == -1; ++i)
    {
        if(Box_Mode ->currentText() == "Left Click")
        {
            ::mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            Sleep(10);
            ::mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(Interval - 10);
        }
        else if(Box_Mode ->currentText() == "Right Click")
        {
            ::mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
            Sleep(10);
            ::mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
            Sleep(Interval - 10);
        }

        if(QCursor::pos().x() != x || QCursor::pos().y() != y)
        {
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
