#ifndef SKILLS_H
#define SKILLS_H

#include "students.h"
using namespace std;
class Skills: public Students
{
public:
    Skills(const string name_1="", const int analitics=0, const int curiosity=0, const int sporty=0, const int pedantry=0, const int writer=0, const string task="");
    Skills(const Skills &skill);
    string getName1() const;
    int getAnalitics() const;
    int getCuriosity() const;
    int getSporty() const;
    int getPedantry() const;
    int getWriter() const;
    string getTask() const;
    void setName1(const string names);
    void setAnalitics(const int analicticss);
    void setCuriosity(const int curuosities);
    void setSporty(const int sporties);
    void setPedantry(const int pedantries);
    void setWriter(const int writers);
    void setTask(const string tasks);
private:
    int analitics, curiosity, sporty, pedantry, writer;
    string name_1, task;
};

#endif // SKILLS_H
