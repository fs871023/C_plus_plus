#include <iostream>
using namespace std;
//using std::ostream;
class Student
{
    friend ostream &operator<<(ostream &,const Student &);
protected:
    char* first_name;
    char* last_name;
    char* course;
public:
    Student();
    Student (char*, char*, char*) ;//constructor
    char* getcourse()const//get course name
    {
        return course;
    }
    virtual const double avg() const {}//virtual avg score
    virtual const int getfinal() const {}//virtual get final score
};
class English : public Student
{
    int att;//Attendance = 10%
    int proj;//Project = 30%
    int midterm;//Midterm = 30%
    int final_eng;//Final Exam = 30%
public:
    virtual const double avg() const;
    virtual const int getfinal() const ;
    English(char*,char*,char*,char*);//constructor
};
class History : public Student
{
    int paper;//Term Paper = 25%
    int midterm;//Midterm = 35%
    int final_hist;//Final Exam = 40%
public:
    virtual const double avg() const;
    virtual const int getfinal() const ;//{ return final_hist; }
    History(char*,char*,char*,char*);
};
class Math : public Student
{
    double quiz_avg;//Quiz Average = 15%
    int test1;//Test 1 = 25%
    int test2;//Test 2 = 25%/
    int final_math;//Final Exam = 35%
public:
    virtual const double avg() const;
    virtual const int getfinal() const ;//{ return final_math; }
    Math(char*,char*,char*,char*);
};
