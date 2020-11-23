#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
using namespace std;
class Students
{
public:
    Students(const string name="", const int height=0);
    Students(const Students &student);
    string getName() const;
    int getHeight() const;
    void setName(const string names);
    void setHeight(const int heights);
    void output() const;
    virtual string getName1() const;
    virtual int getAnalitics() const;
    virtual int getCuriosity() const;
    virtual int getSporty() const;
    virtual int getPedantry() const;
    virtual int getWriter() const;
    virtual string getTask() const;
    virtual void setName1(const string names);
    virtual void setAnalitics(const int analicticss);
    virtual void setCuriosity(const int curuosities);
    virtual void setSporty(const int sporties);
    virtual void setPedantry(const int pedantries);
    virtual void setWriter(const int writers);
    virtual void setTask(const string tasks);
private:
    string name, name_1, task;
    int height;
    int analitics, curiosity, sporty, pedantry, writer;
};

#endif // STUDENTS_H
