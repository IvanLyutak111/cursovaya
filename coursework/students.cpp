#include "students.h"
#include <iostream>
#include "skills.h"
using namespace std;
Students::Students(const string names, const int heights) {
    setName(names);
    setHeight(heights);
};

Students::Students(const Students &student) {
    setName(student.getName());
    setHeight(student.getHeight());
};
string Students::getName() const {
    return name;
};
int Students::getHeight() const {
    return height;
};


void Students::setName(const string names) {
        name = names;
};

void Students::setHeight(const int heights) {
    if (heights <= 0)
        height = 0;
    else if (heights >= 220)
        height = 220;
    else
        height = heights;
};
void Students::output() const {
    cout << "Name: " << name << endl;
    cout << "Height: " << height << endl;
};
string Students::getName1() const{
   return name_1;
}
int Students::getAnalitics() const{
   return analitics;
}
int Students::getCuriosity() const{
   return curiosity;
}
int Students::getSporty() const{
   return sporty;
}
int Students::getPedantry() const{
   return pedantry;
}
int Students::getWriter() const{
   return writer;
}
string Students::getTask() const{
   return task;
}
void Students::setName1(const string names) {
   name_1 = names;
}
void Students::setAnalitics(const int analiticss) {
    if (analiticss<=0)
        analitics = 0;
    else if (analiticss>=10)
        analitics=10;
    else
      analitics = analiticss;
}
void Students::setCuriosity(const int curiosities){
    if (curiosities<=0)
        curiosity = 0;
    else if (curiosities>=10)
        curiosity=10;
    else
     curiosity=curiosities;
}
void Students::setSporty(const int sporties){
    if (sporties<=0)
        sporty = 0;
    else if (sporties>=10)
        sporty=10;
    else
      sporty = sporties;
}
void Students::setPedantry(const int pedantries){
    if (pedantries<=0)
        pedantry = 0;
    else if (pedantries>=10)
        pedantry=10;
    else
      pedantry = pedantries;
}
void Students::setWriter(const int writers){
    if (writers<=0)
        writer = 0;
    else if (writers>=10)
        writer=10;
    else
        writer = writers;
}
void Students::setTask(const string tasks){
    task=tasks;
}


