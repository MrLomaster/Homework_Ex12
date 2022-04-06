#include <iostream>
#include "student.h"
#include "subject.h"
#include <vector>
#include <clocale>
#include <windows.h>
#include <stdlib.h>

using namespace std;

vector<string> Split(string line,char splitter)
{
    vector<string> commands;
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
vector<int> InputMark()
{
   vector<int> buff;
   vector<string> buffs;
   vector<string>::iterator it;
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
vector<Subject> InputSbujects()
{
   Subject obj1;
   vector<Subject> buff;
   vector<int> marks;
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
    vector<Student> Students;
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
    vector<Student>::iterator it;
    for(it=Students.begin();it!=Students.end();it++)
    {
       obj1=*it;
       obj1.PrintSdudent();
    }
//-----------------------------------------------------------------
    return 0;
}
