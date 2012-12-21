#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();
    this->cnt = 0;
    QTimer *iTimer = new QTimer(this);
    iTimer->setInterval(10);

    QObject::connect(iTimer, SIGNAL(timeout()), this, SLOT(updateUI()));

    iTimer->start();

    /* Read Button */
    br = new ButtonRead(this);
    QObject::connect(br, SIGNAL(buttonChanged(int, int)), this, SLOT(updateButtons(int, int)));
    br->start();
}

void MainWindow::updateUI()
{

    this->cnt ++;

    if(this->cnt / 10 >= 100){
        ui->pgbTest->setValue(0);
        this->cnt = 0;
    }
    ui->pgbTest->setValue(this->cnt/10);
}

void MainWindow::updateButtons(int number, int value){
    QLabel *mylb;
    switch (number){
    case 0:
        mylb = ui->lbKey0;
        break;
    case 1:
        mylb = ui->lbKey1;
        break;
    case 2:
        mylb = ui->lbKey2;
        break;
    case 3:
        mylb = ui->lbKey3;
        break;
    default:
        mylb = ui->lbKey0;
        break;
    }

    if(value == 2){
        mylb->setPixmap(QPixmap(":/button_on.png"));
    }else{
        mylb->setPixmap(QPixmap(":/button_off.png"));
    }
}

MainWindow::~MainWindow()
{
    br->terminate();
    br->~ButtonRead();
    delete ui;
}
