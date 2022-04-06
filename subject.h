#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Subject
{
      string SubjectName;
      list<int> Marks;
public:
    Subject();
    void Vvod(string name,list<int> marks)
    {

            SubjectName=name;
            Marks=marks;
    }
    void PrintMark()
    {
        list<int>::iterator it;
        for(it=Marks.begin();it!=Marks.end();it++)
        {
           cout<<*it<<" ";
        }
    }
    void PrintSubject()
    {
        cout<<SubjectName<<"\t";
        PrintMark();
        cout<<endl;
    }
};

#endif // SUBJECT_H
