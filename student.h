#ifndef STUDENT_H
#define STUDENT_H
#include "subject.h"
#include <iostream>
#include <vector>

using namespace std;


class Student
{
    string Fio;
    vector<Subject> Pred;

public:
    Student();
    void SetFio(string fio)
    {
         Fio=fio;
    }

    void addSubjects( vector<Subject> allsub)
    {
        Pred=allsub;
    }

    void PrintSdudent()
    {
        vector<Subject>::iterator it;
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
