#ifndef STUDENT_H
#define STUDENT_H
#include "subject.h"
#include <list>
#include <iostream>
#include <vector>

using namespace std;


class Student
{
    string Fio;
    list<Subject> Pred;

public:
    Student();
    void SetFio(string fio)
    {
         Fio=fio;
    }

    void addSubjects( list<Subject> allsub)
    {
        Pred=allsub;
    }

    void PrintSdudent()
    {
        list<Subject>::iterator it;
        Subject subject;
        cout << '\t' <<Fio<<"\t" << '\n';
        cout << '\n';
        for(it=Pred.begin();it!=Pred.end();it++)
        {
           subject=*it;
           subject.PrintSubject();
        }
    }
};

#endif // STUDENT_H
