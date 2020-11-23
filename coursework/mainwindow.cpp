#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow1.h"
#include "mainwindow2.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(gto1()));
     QObject::connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(gto2()));
}
void gto1(){
    auto swindow = new MainWindow1();
    swindow->setWindowTitle("");
    swindow->show();
}
void gto2(){
    auto swindow2 = new MainWindow2();
    swindow2->setWindowTitle("");
    swindow2->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

