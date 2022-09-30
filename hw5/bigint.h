#include <iostream>
using namespace std;
class bigint
{
public:
    bigint(); // default constructor, set the value to be 0
    bigint(int ); // set the value to be x0
    bigint(int, int); // set the value to be x1*109+x0
    bigint(int, int, int );  // set the value to be x2*1018+x1*109+x0
    bigint(int, int, int, int );    // set the value to be x3*1027+ x2*1018+x1*109+x0
    bigint(int, int, int, int, int );    // set the value to be x4*1036+ x3*1027+ x2*1018+x1*109+x0

    friend istream& operator>>(istream&, bigint&);
    friend ostream& operator<<(ostream&, const bigint&);

    bigint operator+(const bigint&)const;
    bigint operator+(const int&)const;
    friend bigint operator+(const int&, const bigint&);

    bigint operator-(const bigint&)const;
    bigint operator-(const int&)const;
    friend bigint operator-(const int&, const bigint&);

    bool operator> ( const bigint&)const;
    bool operator< ( const bigint&)const;
    bool operator<=( const bigint&)const;
    bool operator>=( const bigint&)const;
    bool operator==( const bigint&)const;
    bool operator!=( const bigint&)const;
private:
    int v[5];
};
