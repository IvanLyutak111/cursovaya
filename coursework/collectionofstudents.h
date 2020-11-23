#ifndef COLLECTIONOFSTUDENTS_H
#define COLLECTIONOFSTUDENTS_H
#include "students.h"
#include "skills.h"
class CollectionOfStudents
{
public:
    CollectionOfStudents();
    CollectionOfStudents(int n, int m, Students &pur);
    CollectionOfStudents(const CollectionOfStudents &other);
    CollectionOfStudents& operator=(const CollectionOfStudents &other) = delete;
    void setStudents(const int x, const int y, Students &student);
    void setSkills(const int x, const int y, Skills &skill);
    Students &getStudents(const int x, const int y) const;
    Skills &getSkills(const int x, const int y) const;
  void  outputCollect(int x, int y, string &str,int &h );
    void outputCollectSkills(int x, int y,  string &names, int &analiciticss, int &curiositys, int &sportys, int &pedantrys, int &writers, string &tasks);
    CollectionOfStudents getFile(std::string Str) const;
    CollectionOfStudents getFileSkills(std::string StrLED) const;

     void assign(int n);
     void regulation(int n);
    ~CollectionOfStudents();
private:
    Students ***collect{nullptr};
    Skills **collectSkills{nullptr};
    int nn{0}, mm{0};
};

#endif // COLLECTIONOFSTUDENTS_H
