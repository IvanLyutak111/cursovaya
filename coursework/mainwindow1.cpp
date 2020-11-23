#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <QTextEdit>
#include <QMessageBox>
using namespace std;
MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    QObject::connect(ui->transform_button,SIGNAL(clicked()), this, SLOT(transform()));
    QObject::connect(ui->download_button,SIGNAL(clicked()), this, SLOT(download()));
     QObject::connect(ui->load_button,SIGNAL(clicked()), this, SLOT(load()));
}
int n=0;
void MainWindow1::transform(){
   cout << "transform"<<endl;
    string line;
    QString str="";
    string str1;
     int h=0;
   QString name = ui->download->text();
   std::ifstream in(name.toStdString());
   if(in.is_open()){
       getline(in, line);
       n = atoi(line.c_str())/3;
       if (atoi(line.c_str())%3>0){
           n++;
       }
       in.close();
       auto pur = new Students();
        CollectionOfStudents square(n,3, *pur);
         for (int i=0;i < n;i++){
             for(int j=0; j<3;j++){
                  QTableWidgetItem *item = ui->tableWidget->item(i,j);
                  QStringList strList = item->text().split(QRegExp("[\n]"),QString::SkipEmptyParts);
                  cout << strList[0].toStdString()<<endl;
                 string f1= strList[0].toStdString();
                 int f2= strList[1].toInt();
                  square.setStudents(i, j,*(new Students(f1, f2)));
             }
         }
         square.regulation(n);
         for(int i=0; i< n;i++){
             for (int j=0;j<3;j++){
                 str1=str.toStdString();
                 square.outputCollect(i,j, str1,h);
                 str = QString::fromStdString(str1);
                 cout << "Enter"<<endl;
                 cout << str.toStdString() << endl;
                 cout << h << endl;
                 if(str!=""){
                     QTableWidgetItem *itm = new QTableWidgetItem(str+"\n"+QString::number(h));
                       ui->tableWidget->setItem(i,j,itm);
                 }

             }
             }
   }
   else{
       QMessageBox::critical(this, "Ошибка", "Cначала загрузите файл");
   }
}
int count1=0;
void MainWindow1::download(){
    cout << "download"<<endl;
    string line;
    QString name = ui->download->text();
    std::ifstream in(name.toStdString());
    if(in.is_open()){
        getline(in, line);
        n = atoi(line.c_str())/3;
        if (atoi(line.c_str())%3>0){
            n++;
        }
        in.close();
     CollectionOfStudents led;
     CollectionOfStudents pur = led.getFile(name.toStdString());
     ui->tableWidget->setColumnCount(3);
     ui->tableWidget->setRowCount(n);
    QString str="";
    string str1;
     int h=0;
     count1=0;
     for(int i=0; i< n;i++){
         for (int j=0;j<3;j++){
             str1=str.toStdString();
             pur.outputCollect(i,j, str1,h);
             str = QString::fromStdString(str1);
             cout << "Enter"<<endl;
             cout << str.toStdString() << endl;
             cout << h << endl;
             if(str!=""){
                 count1++;
                 QTableWidgetItem *itm = new QTableWidgetItem(str+"\n"+QString::number(h));
                   ui->tableWidget->setItem(i,j,itm);
             }

         }
         }
    }
    else
   {
        cout << "didnot open"<< endl;
        QMessageBox::critical(this, "Ошибка", "Файл не существует");
   }
}
void MainWindow1::load(){
    cout << "load" << endl;
    QString name = ui->load->text();
    ofstream fout(name.toStdString() , std::ios::app);
    if(fout.is_open()){
        QMessageBox:: StandardButton reply = QMessageBox::question(this, "Сохранение файла", "Уверены что хотите сохранить ", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
             std::ofstream ofs;
            ofs.open(name.toStdString(), std::ofstream::out | std::ofstream::trunc);
            ofs.close();
         fout << count1 << endl;
         for (int i=0;i < n;i++){
             for(int j=0;j<3;j++){
                 QTableWidgetItem *item = ui->tableWidget->item(i,j);
                 QStringList strList = item->text().split(QRegExp("[\n]"),QString::SkipEmptyParts);

                string f1= strList[0].toStdString();
                int f2= strList[1].toInt();
                fout << f1 << endl;
                fout << f2 << endl;
}
         }
         fout << "/" <<endl;
         fout.close();
         QMessageBox::information(this, "Информация", "Файл успешно сохранен");
    }
    }
    else{
        QMessageBox::critical(this, "Ошибка", "Не допустимое название файла");
    }


}
MainWindow1::~MainWindow1()
{
    delete ui;
}
