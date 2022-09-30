#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>

#include "Student.h"
using namespace std;

char grade(const double & score)//transform Avg to Grade
{
    if(score>100||score<0)
        return 'X';
    if(score>=90)
        return 'A';
    else if(score>=80)
        return 'B';
    else if(score>=70)
        return 'C';
    else if(score>=60)
        return 'D';
    else
        return 'F';
}

int main()
{
    char inname[20];
    char outname[20];
    ifstream fin;
    ofstream fout;
    cout<<"Please enter the name of the input file."<<endl;
    cout<<"Filename:";
    cin>>inname;
    fin.open(inname);
    if(!fin)
    {
        cerr<<"file open error"<<endl;
        return 0;
    }
    cout<<endl;

    string str;
    getline(fin,str);
    int size_n=atoi(str.c_str());//the number of students
    Student * lst;
    lst = new Student [size_n];

    char temp_fstname[20];
    char temp_lastname[20];
    char temp_course[20];
    char score[40];
    for(int i=0; i<size_n; i++) //put data in array
    {
        getline(fin,str,',');//read student name
        strcpy(temp_lastname, str.c_str());
        getline(fin,str);//read student score
        strcpy(temp_fstname, str.c_str());
        getline(fin,str,' ');//read student course
        strcpy(temp_course, str.c_str());
        getline(fin,str);//read score
        strcpy(score, str.c_str());


        if(strcmp(temp_course,"Math")==0)
            lst[i]=Math(temp_fstname, temp_lastname, temp_course, score);// construct Math
        else if(strcmp(temp_course,"History")==0)
            lst[i]=History(temp_fstname,temp_lastname, temp_course, score);// construct History
        else if(strcmp(temp_course, "English")==0)
            lst[i]=English(temp_fstname, temp_lastname, temp_course, score);// construct English
        else
            cout<<"course name error!"<<endl;
    }
    cout<<"Please enter the name of the output file."<<endl;
    cout<<"Filename:";
    cin>>outname;
    fout.open(outname);
    if(!fout)
    {
        cerr<<"file open error"<<endl;
        return 0;
    }
    cout<<endl;
//put into output
    fout<< "Student Grade Summary"<<endl;
    fout<< "----------------------------------"<<endl;
    fout<< "ENGLISH CLASS"<<endl;
    fout<<endl;
    fout<< setw(15)<<"Student Name"
        << setw(15)<<"final Exam"
        << setw(15)<<"Final Avg"
        << setw(15)<<"Letter Grade"<<endl;
    fout<< "--------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<size_n; ++i)
    {
        if(strcmp(lst[i].getcourse(),"English")==0)
        {
            fout<<setw(15)<<fixed<<lst[i]
                <<setw(15)<<fixed<<lst[i].getfinal()
                <<setw(15)<<fixed<<setprecision(2)<<lst[i].avg()
                <<setw(15)<<fixed<<grade(lst[i].avg())<<endl;
        }
    }
    fout<<endl;

    fout<< "HISTORY CLASS"<<endl;
    fout<<endl;
    fout<< setw(15)<<"Student Name"
        << setw(15)<<"final Exam"
        << setw(15)<<"Final Avg"
        << setw(15)<<"Letter Grade"<<endl;
    fout<< "--------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<size_n; ++i)
    {
        if(strcmp(lst[i].getcourse(),"History")==0)
        {
            fout<<setw(15)<<lst[i]
                <<setw(15)<<lst[i].getfinal()
                <<setw(15)<<fixed<<setprecision(2)<<lst[i].avg()
                <<setw(15)<<grade(lst[i].avg())<<endl;
        }
    }
    fout<<endl;

    fout<< "MATH CLASS"<<endl;
    fout<<endl;
    fout<< setw(15)<<"Student Name"
        << setw(15)<<"final Exam"
        << setw(15)<<"Final Avg"
        << setw(15)<<"Letter Grade"<<endl;
    fout<< "--------------------------------------------------------------------------------"<<endl;
    for(int i=0; i<size_n; ++i)
    {
        if(strcmp(lst[i].getcourse(),"Math")==0)
        {
            fout<<setw(15)<<lst[i]
                <<setw(15)<<lst[i].getfinal()
                <<setw(15)<<fixed<<setprecision(2)<<lst[i].avg()
                <<setw(15)<<grade(lst[i].avg())<<endl;
        }
    }
    fout<<endl;

    cout<<"Processing Complete."<<endl;


    return 0;
}
