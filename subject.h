#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <vector>

using namespace std;

class Subject
{
      string SubjectName;
      vector<int> Marks;
public:
    Subject();
    void Vvod(string name,vector<int> marks)
    {

            SubjectName=name;
            Marks=marks;
    }
    void PrintMark()
    {
        vector<int>::iterator it;
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
