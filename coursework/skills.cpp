#include "skills.h"
#include <iostream>
using namespace std;
Skills::Skills(const string name_1s, const int analiticss, const int curiositys, const int sportys, const int pedantrys, const int writers, const string tasks){
      setName1(name_1s);
     setAnalitics(analiticss);
      setCuriosity(curiositys);
      setSporty(sportys);
      setPedantry(pedantrys);
      setWriter(writers);
}
Skills::Skills(const Skills &skill)
{
    setName(skill.getName());
    setAnalitics(skill.getAnalitics());
    setCuriosity(skill.getCuriosity());
    setSporty(skill.getSporty());
    setPedantry(skill.getPedantry());
    setWriter(skill.getWriter());
}
string Skills::getName1() const{
    return name_1;

}
int Skills::getAnalitics() const{
    return analitics;
}
int Skills::getCuriosity() const{
    return curiosity;
}
int Skills::getSporty() const{
    return sporty;
}
int Skills::getPedantry() const{
    return pedantry;
}
int Skills::getWriter() const{
    return writer;
}
string Skills::getTask() const{
    return task;
}
void Skills::setName1(const string names) {
   name_1 = names;
}
void Skills::setAnalitics(const int analiticss) {
    if (analiticss<=0)
        analitics = 0;
    else if (analiticss>=10)
        analitics=10;
    else
      analitics = analiticss;
}
void Skills::setCuriosity(const int curiosities){
    if (curiosities<=0)
        curiosity = 0;
    else if (curiosities>=10)
        curiosity=10;
    else
     curiosity=curiosities;
}
void Skills::setSporty(const int sporties){
    if (sporties<=0)
        sporty = 0;
    else if (sporties>=10)
        sporty=10;
    else
      sporty = sporties;
}
void Skills::setPedantry(const int pedantries){
    if (pedantries<=0)
        pedantry = 0;
    else if (pedantries>=10)
        pedantry=10;
    else
      pedantry = pedantries;
}
void Skills::setWriter(const int writers){
    if (writers<=0)
        writer = 0;
    else if (writers>=10)
        writer=10;
    else
        writer = writers;
}
void Skills::setTask(const string tasks){
    task = tasks;
}
