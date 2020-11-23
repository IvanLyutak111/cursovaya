#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <QTextEdit>
#include <QMessageBox>
#include "collectionofstudents.h"
MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    QObject::connect(ui->assign_button,SIGNAL(clicked()), this, SLOT(assign()));
    QObject::connect(ui->download_button,SIGNAL(clicked()), this, SLOT(download()));
     QObject::connect(ui->load_button,SIGNAL(clicked()), this, SLOT(load()));
}
int n1=0;
int pip=0;
void MainWindow2::assign(){
     cout << "assign" << endl;
     string line;
     QString name = ui->download->text();
     std::ifstream in(name.toStdString());
     if(in.is_open()){
         getline(in, line);
         n1 = atoi(line.c_str())/3;
         if (atoi(line.c_str())%3>0){
             n1++;
         }
         in.close();
         ui->textBrowser_2->setText("");
      CollectionOfStudents led;
      CollectionOfStudents pur = led.getFileSkills(name.toStdString());
     QString names="";
     string names1, tasks;
      int analiciticss=0, curiositys=0,sportys=0, pedantrys=0, writers=0;
      pur.assign(n1);
      pip=0;
      for(int i=0; i< n1;i++)
          for (int j=0;j<3;j++){
              names1=names.toStdString();
              pur.outputCollectSkills(i,j, names1,analiciticss,curiositys,sportys,pedantrys,writers,tasks);
              names = QString::fromStdString(names1);
              if (tasks!=""){
                  pip++;
                  ui->textBrowser_2->append("Power= "+names);
                   ui->textBrowser_2->append("Analitics= "+QString::number(analiciticss));
                   ui->textBrowser_2->append("Curiosity= "+QString::number(curiositys));
                    ui->textBrowser_2->append("Sporty= "+QString::number(sportys));
                     ui->textBrowser_2->append("Pedantry= "+QString::number(pedantrys));
                      ui->textBrowser_2->append("Writer= "+QString::number(+writers));
                      ui->textBrowser_2->append("Task= "+ QString::fromStdString(tasks));
          }
          }
     }
}
void MainWindow2::download(){
     cout <<"download" << endl;
     string line;
     QString name = ui->download->text();
     std::ifstream in(name.toStdString());
     if(in.is_open()){
         ui->textBrowser->setText("");
         getline(in, line);
         n1 = atoi(line.c_str())/3;
         if (atoi(line.c_str())%3>0){
             n1++;
         }
         in.close();
      CollectionOfStudents led;
      CollectionOfStudents pur = led.getFileSkills(name.toStdString());
     QString names="";
     string names1, tasks;
      int analiciticss=0, curiositys=0,sportys=0, pedantrys=0, writers=0;
      for(int i=0; i< n1;i++){
          for (int j=0;j<3;j++){
              names1=names.toStdString();
              pur.outputCollectSkills(i,j, names1,analiciticss,curiositys,sportys,pedantrys,writers,tasks);
              names = QString::fromStdString(names1);
              cout << "Enter"<<endl;
              if(names!=""){

                   ui->textBrowser->append("Power= "+names);
                    ui->textBrowser->append("Analitics= "+QString::number(analiciticss));
                    ui->textBrowser->append("Curiosity= "+QString::number(curiositys));
                     ui->textBrowser->append("Sporty= "+QString::number(sportys));
                      ui->textBrowser->append("Pedantry= "+QString::number(pedantrys));
                       ui->textBrowser->append("Writer= "+QString::number(+writers));
                       if(tasks != ""){
                       ui->textBrowser->append("Task= "+ QString::fromStdString(tasks));
                       }
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
void MainWindow2::load(){
    cout << "load"<<endl;

    cout << "OUTPUT" << endl;
    QString name = ui->load->text();
    ofstream fout(name.toStdString() , std::ios::app);
    if(fout.is_open()){
        QMessageBox:: StandardButton reply = QMessageBox::question(this, "Сохранение файла", "Уверены что хотите сохранить ", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
             std::ofstream ofs;
            ofs.open(name.toStdString(), std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            fout <<pip<<endl;
            fout << ui->textBrowser_2->toPlainText().toStdString()<<endl;
            fout << "/"<<endl;
            fout.close();
            QMessageBox::information(this, "Информация", "Файл успешно сохранен");
        }
    }
    else{
        QMessageBox::critical(this, "Ошибка", "Не допустимое название файла");
    }

}
MainWindow2::~MainWindow2()
{
    delete ui;
}
