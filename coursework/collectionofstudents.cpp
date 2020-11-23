#include "collectionofstudents.h"
#include "students.h"
#include "skills.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <assert.h>
CollectionOfStudents::CollectionOfStudents()
{
}
CollectionOfStudents::CollectionOfStudents(const int n,const int m, Students &pur) {
        if (n > 0 && m > 0) {
           cout << &pur << endl;
           collect = new Students **[n];
            for (int i = 0; i < n; i++) {
                collect[i] = new Students *[m];
                for (int j = 0; j < m; j++)
                {
                   collect[i][j] = &pur;
                }
            }
            nn = n;
            mm = m;
        }
    else
            throw 1;
    };

CollectionOfStudents::CollectionOfStudents(const CollectionOfStudents &other) {
        if (other.nn > 0 && other.mm > 0) {

            collect = new Students **[other.nn];
            for (int i = 0; i < other.nn; i++) {
               collect[i] = new Students *[other.mm];
                for (int j = 0; j < other.mm; j++)
                {
                   collect[i][j] = other.collect[i][j];
                }
            }
            nn = other.nn;
            mm = other.mm;
        }
        else
            throw 1;
         }
Students &CollectionOfStudents::getStudents(const int x, const int y) const {
        if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
            return *collect[x][y];
        }
        else
            throw 1;
    };
    Skills &CollectionOfStudents::getSkills(const int x, const int y) const {
        if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
            return collectSkills[x][y];
        }
        else
            throw 1;
    };
void CollectionOfStudents::setStudents(const int x, const int y, Students &student) {
        if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
            collect[x][y] = &student;
        }
        else
            throw 1;
    };
void CollectionOfStudents::setSkills(const int x, const int y, Skills &skill) {
        if ((x >= 0) && (x < nn) && (y >= 0) && (y < mm)){
            collect[x][y]=&skill;
        }
        else
            throw 1;
    };

void CollectionOfStudents::outputCollect(int x, int y, string &str,int &h ){
    str=collect[x][y]->getName();
    h=collect[x][y]->getHeight();
    cout << "Name: " << collect[x][y]->getName() << endl;
    cout << "Height: " << collect[x][y]->getHeight() << endl;
}
void CollectionOfStudents::outputCollectSkills(int x, int y, string &names, int &analiciticss, int &curiositys, int &sportys, int &pedantrys, int &writers, string &tasks){
   names= collect[x][y]->getName1();
   analiciticss = collect[x][y]->getAnalitics();
   curiositys = collect[x][y]->getCuriosity();
   sportys = collect[x][y]->getSporty();
   pedantrys=collect[x][y]->getPedantry();
   writers=collect[x][y]->getWriter();
   tasks=collect[x][y]->getTask();
    cout << "Name: " << collect[x][y]->getName1() << endl;
    cout << "Analictics: " << collect[x][y]->getAnalitics() << endl;
     cout << "Curiosity: " << collect[x][y]->getCuriosity() << endl;
      cout << "Sporty: " << collect[x][y]->getSporty() << endl;
       cout << "Pedantry: " << collect[x][y]->getPedantry() << endl;
        cout << "Writer: " << collect[x][y]->getWriter() << endl;
        cout << "Task:"<<collect[x][y]->getTask()<<endl;

}
CollectionOfStudents CollectionOfStudents:: getFile(string Str) const{
    string line, str;
    int n,m, power,intensitive, size, x=0, y=0;
        std::ifstream in(Str); // окрываем файл для чтения
        if (in.is_open())
        {
            getline(in, line);
            n = atoi(line.c_str())/3;
            if (atoi(line.c_str())%3>0){
                n++;
            }
           m = 3;
           auto pur = new Students();
            CollectionOfStudents square(n, m, *pur);
            cout << "begin" << endl;
            cout << n <<endl;
            while (getline(in, line))
            {
                if (line == "/") break;
                str = line.c_str();
                getline(in, line);
                size = atoi(line.c_str());
                square.setStudents(x, y,*(new Students(str, size)));
                //square.outputCollect(x,y);
                if(y<2)
                    y++;
                else{
                    x++;
                    y=0;
                }
            }
        //square.regulation(n);
            return square;
        }
        in.close(); // закрываем файл

};
void CollectionOfStudents::regulation(int n){
    Students *c;
     cout << "Before Regulation" << endl;
     cout << "n="<<n<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
             if( collect[i][j]->getName()!=""){
                 cout << "i="<<i<<" ,j="<<j<<endl;
          cout <<  collect[i][j]->getName() << endl;
           cout << collect[i][j]->getHeight()<< endl;
             }
        }
    for(int i=0;i<n;i++)
        for(int j=2;j>-1;j--)
            for(int k=i;k<n;k++)
                for(int g=j;g>-1;g--){
                    if(collect[i][j]->getHeight()<collect[k][g]->getHeight()){
                        c = collect[i][j];
                        collect[i][j]=collect[k][g];
                        collect[k][g]=c;
                    }
                }
   cout << "After Regulation" << endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
           if( collect[i][j]->getName()!=""){
                  cout << "i="<<i<<" ,j="<<j<<endl;
         cout <<  collect[i][j]->getName()<<endl;
         cout<<  collect[i][j]->getHeight()<<endl;
        }
        }
}
void CollectionOfStudents::assign(int n){
    cout << "Assign"<<endl;
    int max_analitics=0,max_curiosity=0,max_sporty=0,max_pedantry=0,max_writer=0;
    int i_analitics=-1, i_curiosity=-1, i_sporty=-1, i_pedantry=-1, i_writer=-1,j_analitics=-1, j_curiosity=-1, j_sporty=-1, j_pedantry=-1, j_writer=-1;
    cout << "n="<<n<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
             if( collect[i][j]->getName1()!="" && collect[i][j]->getTask()==""){
                 cout << "analictic="<<collect[i][j]->getAnalitics();
                 cout << "max="<<max_analitics<<endl;
                 if(collect[i][j]->getAnalitics()>max_analitics){
                     cout << "Check"<<endl;
                     if(i_analitics!=-1 && j_analitics!=-1){
                          collect[i_analitics][j_analitics]->setTask("");
                     }
                     max_analitics=collect[i][j]->getAnalitics();
                     collect[i][j]->setTask("Доклад по теме занятия");
                     i_analitics=i;
                     j_analitics=j;
                 }
             }
             }
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
             if( collect[i][j]->getName1()!="" && collect[i][j]->getTask()==""){
                 if(collect[i][j]->getCuriosity()>max_curiosity){
                     if(i_curiosity!=-1 && j_curiosity!=-1){
                          collect[i_curiosity][j_curiosity]->setTask("");
                     }
                     max_curiosity=collect[i][j]->getCuriosity();
                     collect[i][j]->setTask("Созданние новостной сводки");
                     i_curiosity=i;
                     j_curiosity=j;
                 }
             }
             }
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
             if( collect[i][j]->getName1()!="" && collect[i][j]->getTask()==""){

                 if(collect[i][j]->getSporty()>max_sporty){
                     if(i_sporty!=-1 && j_sporty!=-1){
                          collect[i_sporty][j_sporty]->setTask("");
                     }
                     max_sporty=collect[i][j]->getCuriosity();
                     collect[i][j]->setTask("Спортсмен");
                     i_sporty=i;
                     j_sporty=j;
                 }
             }
             }
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++){
             if( collect[i][j]->getName1()!="" && collect[i][j]->getTask()==""){
                 if(collect[i][j]->getPedantry()>max_pedantry || collect[i][j]->getWriter()>max_writer){
                     if(i_pedantry!=-1 && j_pedantry!=-1){
                          collect[i_pedantry][j_pedantry]->setTask("");
                          collect[i_writer][j_writer]->setTask("");
                     }
                     max_pedantry=collect[i][j]->getPedantry();
                             max_writer=collect[i][j]->getWriter();
                     collect[i][j]->setTask("Журналист");
                     i_pedantry=i;
                     j_pedantry=j;
                     i_writer=i;
                     j_writer=j;
                 }
             }
             }
    cout << "The end"<<endl;
    cout << max_analitics << endl;
}
CollectionOfStudents CollectionOfStudents:: getFileSkills(string StrLED) const{
    string line;
    int n,m, x=0, y=0;
    string str, task;
    int analitics, curiosity, sporty, pedantry, writer;
    std::ifstream in(StrLED); // окрываем файл для чтения
    if (in.is_open()){
        getline(in, line);
        n = atoi(line.c_str())/3;
        if (atoi(line.c_str())%3>0){
            n++;
        }
       m = 3;
       cout<< "n=" << n << endl;
       auto pur = new Skills();
        CollectionOfStudents room(n, m, *pur);
        while (getline(in, line))
        {
            if (line == "/") break;
            str = line.c_str();
            cout << str << endl;
            getline(in, line);
            analitics = atoi(line.c_str());
            getline(in, line);
            curiosity = atoi(line.c_str());
            getline(in, line);
            sporty = atoi(line.c_str());
            getline(in, line);
            pedantry = atoi(line.c_str());
            getline(in, line);
            writer = atoi(line.c_str());
            getline(in, line);
            task = line.c_str();
            cout << "coordinate"<<endl;
            cout << x <<endl;
            cout << y << endl;
            room.setSkills(x,y, *(new Skills(str, analitics,curiosity,sporty,pedantry,writer,task)));
           room.outputCollectSkills(x,y,  str, analitics, curiosity, sporty,pedantry, writer, task);
            if(y<2)
                y++;
            else{
                x++;
                y=0;
            }
        }
        in.close();
        cout << "GOOD" << endl;
    return room;
    }
}



CollectionOfStudents::~CollectionOfStudents() {
    cout << "delete" << endl;
     if (collect) {
        for (int i = 0; i < nn; i++){
            delete [] collect[i];
        }
        delete [] collect;
    }
};

