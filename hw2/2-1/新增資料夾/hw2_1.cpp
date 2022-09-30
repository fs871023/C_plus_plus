#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream openfile;
    openfile.open("data.txt");//open file
    if(!openfile.is_open()){//check if it is opened
        return 1;
    }
    int num[20];//declare
    int i=0;//count how many numbers , and put in right place

    while(openfile>>num[i])//put numbers into array
    {
       i++;
    }
    openfile.close();//close file
    if(i==0)
        cout<<"no data in file"<<endl;
    else
    {
        cout<<"Largest = "<<Large(num,i)<<endl;
        cout<<"Average = "<< Avg(num,i)<<endl;
        cout<<"Average of Positive Numbers = "<<AvgP(num,i)<<endl;
        cout<<"Average of negative Numbers = "<<AvgN(num,i)<<endl;
    }
    return 0;
}
