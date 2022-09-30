#include "Diamond.h"
#include <math.h>
#include <ctype.h>
#include <iostream>
using namespace std;

Diamond::Diamond(int len,char bdr, char fchar)
{

    side_length=new int;
    border=new char;
    fill_char=new char;

    if (len<1)
        len=1;
    else if(len>39)
        len=39;
    *side_length=len;

    if(isascii(bdr)==1)
        *border=bdr;
    else *border='#';

    if(isascii(fchar)==1)
        *fill_char=fchar;
    else *fill_char='*';
    cout<<"Object is being created"<<endl;
};//constructor
Diamond::~Diamond()
{
    delete side_length;
    delete border;
    delete fill_char;
    cout << "Object is being deleted" << endl;
};//destructor
int Diamond::GetSize (void) const
{
    return *side_length;
};
int Diamond::Perimeter(void) const
{
    return (*side_length)*4;
};
double Diamond::Area(void) const
{
    double a=*side_length;
    a=a*a*0.5*sqrt(3);
    return a;
};
void Diamond::Grow(void)
{
    (*side_length) ++;
    if(*side_length > 39)
        *side_length=39;
};
void Diamond::Shrink(void)
{
    (*side_length)--;
    if(*side_length < 1)
        (*side_length)=1;
};
void Diamond::SetBorder(char a)
{
    if(isascii(a)==0)
        *border=a;
    else *border='#';
};
void Diamond::SetFill(char a)
{
    if(isascii(a)==0)
        *fill_char=a;
    else *fill_char='*';
};
void Diamond::Draw(void) const
{
    int length=*side_length;
    char bd=*border;
    char fc=*fill_char;
    for(int i=1,n=length-1; i<=length; i++,n--) //print the up side triangle
    {
        //i means how many rows, n means how many space before border
        for(int k=n; k>0; k--) //print space
        {
            cout<<" ";
        }
        if(i==1)
        {
            cout<<bd<<endl;
        }
        else if(i==2)
        {
            cout<<bd<<" "<<bd<<endl;
        }
        else
        {
            cout<<bd<<" ";
            for(int j=0; j<i-2; j++)
            {
                cout<<fc<<" ";//border
            }
            cout<<bd<<endl;
        }
    }
    for(int i=length-1,n=1; i>0; i--,n++)//print the down side triangle
    {
        //i means how many rows, n means how many space before border
        for(int k=n; k>0; k--)
        {
            cout<<" ";
        }
        if(i==1)
        {
            cout<<bd<<endl;
        }
        else if(i==2)
        {
            cout<<bd<<" "<<bd<<endl;
        }
        else
        {
            cout<<bd<<" ";//border
            for(int j=i-2; j>0; j--)
            {
                cout<<fc<<" ";
            }
            cout<<bd<<endl;//border
        }
    }
};
void Diamond::Summary(void)
{
    cout<<"Size of diamond's side = "<<GetSize()<<" units."<<endl;
    cout<<"Perimeter of diamond = "<<Perimeter()<<" units."<<endl;
    cout<<"Area of diamond = "<<Area()<<" units."<<endl;
    cout<<"Diamond looks like:"<<endl;
    Draw();
};

