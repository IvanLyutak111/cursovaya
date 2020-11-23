#include "mainwindow_first.h"
#include <iostream>
#include "students.h"
#include "collectionofstudents.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    auto pur1 = new Students();
   CollectionOfStudents student(2,2, *pur1);
    Students Students("Ivan", 80);
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            student.setStudents(i,j,Students);
       //     student.outputCollect(i,j);
         }
     CollectionOfStudents led;
    CollectionOfStudents pur = led.getFile("C:/Users/Dima/coursework/file.txt");
    //CollectionOfStudents led1;
    //CollectionOfStudents pur_1 = led1.getFileSkills("C:/Users/Dima/coursework/file_skills.txt");
    QApplication a(argc, argv);
    MainWindow_first w;
    w.show();
    return a.exec();
}
