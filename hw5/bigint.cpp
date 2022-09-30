#include <iostream>
using namespace std;
#include<string>
#include<cstdlib>
#include <iomanip>
#include "bigint.h"

//constructors
bigint::bigint()// default constructor, set the value to be 0
{
    for(int i=0; i<5; ++i)
    {
        v[i]=0;
    }
}
bigint::bigint(int x0)// set the value to be x0
{
    v[0]=x0;
    for(int i=1; i<5; ++i)
    {
        v[i]=0;
    }
}
bigint::bigint(int x0, int x1)// set the value to be x1*109+x0
{
    v[0]=x0;
    v[1]=x1;
    for(int i=2; i<5; ++i)
        v[i]=0;
}
bigint::bigint(int x0, int x1, int x2)// set the value to be x2*1018+x1*109+x0
{
    v[0]=x0;
    v[1]=x1;
    v[2]=x2;
    v[3]=0;
    v[4]=0;
}
bigint::bigint(int x0, int x1, int x2, int x3)// set the value to be x3*1027+ x2*1018+x1*109+x0
{
    v[0]=x0;
    v[1]=x1;
    v[2]=x2;
    v[3]=x3;
    v[4]=0;
}
bigint::bigint(int x0, int x1, int x2, int x3, int x4)// set the value to be x4*1036+ x3*1027+ x2*1018+x1*109+x0
{
    v[0]=x0;
    v[1]=x1;
    v[2]=x2;
    v[3]=x3;
    v[4]=x4;
}
//i/o
istream &operator>>(istream &input, bigint &bint)//operator >>
{
    string str;
    input>>str;//put cin into string
    string temp;//the str store the split string
    int i=0;
    int j=str.size();//how many digits
    int remain=j%9;//When the number of digits is not a multiple of 9, store the remaining numbers for v[4] conversion
    for(i=0; i<5; ++i)
    {
        j=j-9;//In this way, you can cut to the right 9 digits
        if (j<0)//When the number of remaining digits is less than 9
        {
            j=0;
            temp=str.substr(j,remain);//Store the number of digits from 0 to remain
        }
        else
            temp=str.substr(j,9);//cut
        bint.v[i]=atoi(temp.c_str());//Use atoi to convert a string to an integer
        if(j<=0)//the j is out of bound
            break;
    }
    return input;//enable cin>>x>>y;
}
ostream &operator<<(ostream &output, const bigint &obj)
{
    int i=4;
    while(i>0)//When the left end is 0, ignore
    {
        if(obj.v[i]!=0)
        {
            break;
        }
        else if(obj.v[i]==0)
        {
            i--;
        }
    }//Find the leftmost non-zero digit i
    for(int j=i; j>-1; j--)
    {
        output<<setw(9)<<setfill('0')<<obj.v[j];//put it in output
    }
    return output;//enable cout<<x<<y;
}
//compare
bool bigint::operator>(const bigint &right)const
{
    for(int i=4; i>=0; i--)//Digit by digit, compare from big to small
    {
        if (v[i] > right.v[i])
            return true;
        else if(v[i] < right.v[i])
            return false;
    }
    return false;//Equal condition
}
bool bigint::operator<(const bigint &right)const
{
    for(int i=4; i>=0; --i)//Digit by digit, compare from big to small
    {
        if (v[i] < right.v[i])
            return true;
        else if(v[i] > right.v[i])
            return false;
    }
    return false;//Equal condition
}
bool bigint::operator<=(const bigint &right)const
{
    return ! (*this > right);//Use > to implement
}
bool bigint::operator>=(const bigint &right)const
{
    return ! (*this < right);//Use < to implement
}
bool bigint::operator==(const bigint &right)const
{
    for(int i=0; i<5; ++i)//Digit by digit, compare from big to small
        if(v[i]!=right.v[i])
            return false;
    return true;
}
bool bigint::operator!=(const bigint &right)const
{
    return ! (*this == right);//Use != to implement
}

//operate +
bigint bigint::operator+(const bigint& right)const
{
    bigint _bigint;
    for(int i=0; i<5; ++i)
    {
        _bigint.v[i]=this->v[i]+right.v[i];//copy and operate
    }
    for(int i=0; i<4; ++i) //detect if "num" overflow or not
    {
        if(_bigint.v[i]>999999999)
        {
            _bigint.v[i+1]=_bigint.v[i+1]+_bigint.v[i]/1000000000;
            _bigint.v[i]=_bigint.v[i]%1000000000;
        }
    }
    if(_bigint.v[4]>999999999)//detect if the 4 right most digits of "_bigint" overflowing or not
        _bigint.v[4]=_bigint.v[4]%1000000000;
    return _bigint;
}
bigint bigint::operator+(const int &num)const
{
    bigint _bigint;
    for(int i=0; i<5; i++)//copy left obj to "_bigint"
    {
        _bigint.v[i]=this->v[i];
    }
    if(num>999999999)//detect if "num" overflow or not
    {
        _bigint.v[1]=_bigint.v[1]+num/1000000000;
        _bigint.v[0]=_bigint.v[0]+num%1000000000;
    }
    else
        _bigint.v[0]=_bigint.v[0]+num;
    for(int i=0; i<4; ++i) //detect if the 4 right most digits of "_bigint" overflowing or not
    {
        if(_bigint.v[i]>999999999)
        {
            _bigint.v[i+1]=_bigint.v[i+1]+_bigint.v[i]/1000000000;
            _bigint.v[i]=_bigint.v[i]%1000000000;
        }
    }

    if(_bigint.v[4]>999999999)//detect if Whether the leftmost digit of "_bigint" overflows
        _bigint.v[4]=_bigint.v[4]%1000000000;
    return _bigint;
}
bigint operator+(const int &num, const bigint &Bint_right)
{
    bigint _bigint;
    for(int i=0; i<5; ++i)//copy right obj to "_bigint"
    {
        _bigint.v[i]=Bint_right.v[i];
    }

    if(num>999999999)//detect if "num" overflow or not
    {
        _bigint.v[1]=_bigint.v[1]+num/1000000000;
        _bigint.v[0]=_bigint.v[0]+num%1000000000;
    }
    else
        _bigint.v[0]=_bigint.v[0]+num;
    for(int i=0; i<4; ++i) //detect if the 4 right most digits of "_bigint" overflowing or not
    {
        if(_bigint.v[i]>999999999)
        {
            _bigint.v[i+1]=_bigint.v[i+1]+_bigint.v[i]/1000000000;
            _bigint.v[i]=_bigint.v[i]%1000000000;
        }
    }
    if(_bigint.v[4]>999999999)//detect if Whether the leftmost digit of "_bigint" overflows
        _bigint.v[4]=_bigint.v[4]%1000000000;
    return _bigint;
}
//operate -
bigint bigint::operator-(const bigint &right)const
{
    bigint _bigint;
    for(int i=0; i<5; ++i)
    {
        _bigint.v[i]=this->v[i];//copy left obj to "_bigint"
    }
    if(_bigint>right)
    {
        for(int i=0; i<5; i++)
        {
            if(_bigint.v[i]<right.v[i])//If you find that the subtracted number is not enough
            {
                --_bigint.v[i+1];//Borrow to the next digit to avoid negative answers
                _bigint.v[i]=_bigint.v[i]+1000000000;
            }
            _bigint.v[i]=_bigint.v[i]-right.v[i];//operation
        }
        return _bigint;
    }
    else//Because the answer is less than or equal to 0, output 0
    {
        for(int i=0; i<5; ++i)
        {
            _bigint.v[i]=0;
        }
        return _bigint;
    }

}
bigint bigint::operator-(const int &n)const
{
    bigint _bigint;
	for(int i=0; i<5; ++i)
    {
        _bigint.v[i]=this->v[i];//copy left obj to "_bigint"
    }

    bigint num(n%1000000000,n/1000000000);//make int "n" a bigint
    if(_bigint>num)
    {
        for(int i=0; i<5; i++)
        {
            if(_bigint.v[i]<num.v[i])//If you find that the subtracted number is not enough
            {
                --_bigint.v[i+1];//Borrow from the next digit to avoid negative answers
                _bigint.v[i]=_bigint.v[i]+1000000000;
            }
            _bigint.v[i]=_bigint.v[i]-num.v[i];//operation
        }
        return _bigint;
    }
    else//Because the answer is less than or equal to 0, output 0
    {
        for(int i=0; i<5; ++i)
        {
            _bigint.v[i]=0;
        }
        return _bigint;
    }
}
bigint operator-(const int &n, const bigint &Bint_right)
{
    bigint _bigint;
    for(int i=0; i<5; ++i)
    {
        _bigint.v[i]=Bint_right.v[i];//copy right obj to "_bigint"
    }
    bigint num(n%1000000000,n/1000000000);//make int "n" a bigint
    if(_bigint>num)
    {
        for(int i=0; i<5; i++)
        {
            if(_bigint.v[i]<num.v[i])//If you find that the subtracted number is not enough
            {
                --_bigint.v[i+1];//Borrow from the next digit to avoid negative answers
                _bigint.v[i]=_bigint.v[i]+1000000000;
            }
            _bigint.v[i]=_bigint.v[i]-num.v[i];//operation
        }
        return _bigint;
    }
    else//Because the answer is less than or equal to 0, output 0
    {
        for(int i=0; i<5; ++i)
        {
            _bigint.v[i]=0;
        }
        return _bigint;
    }
}
