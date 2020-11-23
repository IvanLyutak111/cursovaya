#include "mainwindow_first.h"
#include "ui_mainwindow_first.h"
#include "mainwindow1.h"
#include "mainwindow2.h"
MainWindow_first::MainWindow_first(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_first)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_1,SIGNAL(clicked()), this, SLOT(go1()));
     QObject::connect(ui->pushButton_2,SIGNAL(clicked()), this, SLOT(go2()));
}
void MainWindow_first::go1(){
    auto swindow = new MainWindow1();
    swindow->setWindowTitle("Преобразование строя");
    swindow->show();

}
void MainWindow_first::go2(){
    auto swindow1 = new MainWindow2();
    swindow1->setWindowTitle("Назначение обязанностей");
    swindow1->show();

}
MainWindow_first::~MainWindow_first()
{
    delete ui;
}
