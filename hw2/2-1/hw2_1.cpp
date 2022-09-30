#include<iostream>
#include<fstream>
using namespace std;

void Readlist(int Array[], int N)
{
    int i;
    for(i=0; i<N; i++)
    {
        cout<<Array[i]<<" ";//print out the array
    }
    cout<<endl;
}

void Avgs (int Array[ ], int N, float &Ave, float &AveP,float &AveN) //calculate average : sum/n
{
    float sum=0,sumP=0,sumN=0;
    int NP=0,NN=0;
    for(int i=0; i<N; i++)
    {
        sum=sum+Array[i];
        if(Array[i]>0)
        {
            sumP=sumP+Array[i];//add positive ones
            NP++;//count positive ones
        }
        if(Array[i]<0)
        {
            sumN=sumN+Array[i];//add negative ones
            NN++;//count negative ones
        }
    }
    Ave=sum/N;
    AveP=sumP/NP;
    AveN=sumN/NN;
}

int Large (int Array[ ], int N)//find largest
{
    int i;
    int Max=0;
    for(i=0; i<N; i++)
    {
        if(Array[i]>Max)
            Max=Array[i];//replace with the larger one
    }
    return Max;
}

void display(int Array[],int N)//print out value
{

    cout<<"Largest = "<<Large(Array,N)<<endl;
    float Avg=0, AvgP=0,AvgN=0;
    Avgs(Array,N,Avg,AvgP,AvgN);
    cout<<"Average = "<< Avg<<endl;
    cout<<"Average of Positive Numbers = "<<AvgP<<endl;
    cout<<"Average of negative Numbers = "<<AvgN<<endl;
}

int main()
{
    ifstream openfile;
    openfile.open("data.txt");//open file
    if(!openfile.is_open())//check if it is opened
        return 1;

    int num[20];//declare
    int i=0;//count how many numbers , and put in right place

    while(openfile>>num[i])//put numbers into array
    {
        i++;
    }
    openfile.close();//close file
    if(i==0)
        cout<<"no data in file"<<endl;//if no data print it

    display(num,i);
    return 0;
}
