#include "Student.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//constructor
Student::Student()
{
    first_name=NULL;
    last_name=NULL;
    course=NULL;
}
Student::Student(char* first, char* last, char* crs)//constructor
{
    first_name=new char [strlen(first)];
    last_name=new char [strlen(last)];
    course=new char [strlen(crs)];
    strcpy(first_name, first);
    strcpy(last_name, last);
    strcpy(course,crs);
}

English::English(char* first, char* last, char* crs, char* score)
    :Student(first, last, crs)//call student constructor
{
    const char* d=" ";
    char *tmp;
    tmp = strtok(score,d);//cut 'score' and copy to class member
    att=atoi(tmp);
    tmp=strtok(NULL,d);
    proj=atoi(tmp);
    tmp=strtok(NULL,d);
    midterm=atoi(tmp);
    tmp=strtok(NULL,d);
    final_eng=atoi(tmp);
}
History::History(char* first, char* last, char* crs, char* score)
    :Student(first, last, crs)//call student constructor
{
    const char * d =" ";
    char * tmp;
    tmp = strtok(score,d);//cut 'score' and copy to class member
    paper=atoi(tmp);
    tmp=strtok(NULL,d);
    midterm=atoi(tmp);
    tmp=strtok(NULL,d);
    final_hist=atoi(tmp);
}
Math::Math(char* first, char* last, char* crs, char* score)
    :Student(first, last, crs)//call student constructor
{
    const char * d = " ";
    char * tmp;
    tmp =strtok(score,d);//cut 'score' and copy to class member
    double q1=atoi(tmp);
    tmp=strtok(NULL,d);
    double q2=atoi(tmp);
    tmp=strtok(NULL,d);
    double q3=atoi(tmp);
    tmp=strtok(NULL,d);
    double q4=atoi(tmp);
    tmp=strtok(NULL,d);
    double q5=atoi(tmp);

    double quiz_sum=q1+q2+q3+q4+q5;//calculate quiz average
    quiz_avg=quiz_sum/5;

    tmp=strtok(NULL,d);
    test1=atoi(tmp);
    tmp=strtok(NULL,d);
    test2=atoi(tmp);
    tmp=strtok(NULL,d);
    final_math=atoi(tmp);
}
//calculate average of student
const double English::avg() const
{
    return (att*0.1+proj*0.3+midterm*0.3+final_eng*0.3);
}
const double History::avg() const
{
    return (paper*0.25+midterm*0.35+final_hist*0.4);
}
const double Math::avg() const
{
    return (quiz_avg*0.15,test1*0.25+test2*0.25+final_math*0.35);
}
//get student's final
const int English::getfinal() const
{
    return final_eng;
}
const int History::getfinal() const
{
    return final_hist;
}
const int Math::getfinal() const
{
    return final_math;
}

ostream &operator<<(ostream &output, const Student &s)
{//print name of student
    output<<s.first_name<<' '<<s.last_name;
    return output;
}
