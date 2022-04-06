#include <iostream>
#include "student.h"
#include "subject.h"
#include <vector>
#include <list>
#include <clocale>
#include <windows.h>
#include <stdlib.h>

using namespace std;

list<string> Split(string line,char splitter)
{
    list<string> commands;
    string buffer = "", st1=line+" ";
    for(int i=0; i < st1.size(); i++)
    {

        if(st1[i] != splitter)
        {
              buffer += st1[i];
              commands.push_back(buffer);
        }
        else
        {
              buffer = "";
        }
    }

    return commands;
}
list<int> InputMark()
{
   list<int> buff;
   list<string> buffs;
   list<string>::iterator it;
   string line;
   cout<<"Write mark in the line: ";
   getline(cin>>ws,line);
   buffs=Split(line,' ');
   for(it=buffs.begin();it!=buffs.end();it++)
   {
      string mark=*it;
      int mark1=stoi (mark);
      buff.push_back(mark1);
   }
    cout<<endl;

   return buff;
 }
list<Subject> InputSbujects()
{
   Subject obj1;
   list<Subject> buff;
   list<int> marks;
   string pred;
   while (pred!=".")
   {
       cout<<"Write name object: ";
       getline(cin>>ws,pred);
       if (pred!=".")
       {
            marks=InputMark();
            obj1.Vvod(pred,marks);
            buff.push_back(obj1);
       }
   }
   return buff;
}

int main()
{
    //---------------------локаль--------------------------
//    setlocale(LC_ALL, "PL_pl.UTF-8");
//    SetConsoleCP(CP_UTF8);
//    SetConsoleOutputCP(CP_UTF8);
    //----------------------------------------------------- 
   // Не работает

//----------------------------Ввод---------------------------------
    list<Student> Students;
    Student obj1;
    string fio;
    while(fio!=".")
    {
        cout<<"Write Fio: ";
        getline(cin>>ws,fio);
        if (fio!=".")
        {
            obj1.SetFio(fio);
            obj1.addSubjects(InputSbujects());
            Students.push_back(obj1);
        }
    }
//-----------------------------------------------------------------
//----------------------------Вывод--------------------------------
    cout<<"Output: "<<endl;
    list<Student>::iterator it;
    for(it=Students.begin();it!=Students.end();it++)
    {
       obj1=*it;
       obj1.PrintSdudent();
    }
//-----------------------------------------------------------------
    return 0;
}
