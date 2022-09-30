#include <iostream>
using namespace std;

#include "Polygon.h"
Polygon::Polygon (unsigned int m = 0, unsigned int n = 0)
{
    _m=m;//
    _n=n;
    _point=new double* [m];//declare m space for point
	for(int i=0; i<m; i++)//use "for" to declare n space
		_point[i]=new double[n];
    cout << "default constructor" << endl;
}
// copy constructor
Polygon::Polygon (const Polygon& mt)
{
	_m=mt._m;//copy m and n
	_n=mt._n;
	_point=new double* [mt._m];//declare m space
	for(int i= 0; i<_m; i++)
	{
		_point[i]=new double[_n];//declare n space
		for(int j=0; j<_n; j++)
			_point[i][j]=mt._point[i][j];//copy value to Polygon
	}

    cout << "copy constructor" << endl;
}
// destructor
Polygon::~Polygon ()
{
	for(int i=0; i<_m; i++)//delete value by using "for"
		delete [] _point[i];
    delete [] _point;
    cout << "destructor" << endl;

}

double* Polygon::FindCentroid() const
{
	double *centroid=new double [_n];//a space to store the centroid point coordinate
	double sum;	//the sum of a coordinate of all points
	for(int i=0;i<_n;i++)
	{
		sum=0;//initialize
		for(int j=0; j<_m; j++)
			sum=sum+getValue(j,i);
		centroid[i]=sum/_m;//the sum divide by the number of points
	}
	return centroid;
} // return the centroid of the polygon

const int Polygon::getNumOfPoints() const
{
    return _m;
}
const int Polygon::getDimension() const
{
    return _n;
}
//: Get the value stored at the m-th point and n-th dimension
const double Polygon::getValue (unsigned int m, unsigned int n) const
{
    if (m<0 || m>=_m || n<0 || n>=_n)
    {
        cerr << "ERROR: index our of range" << endl;
        exit(-1);
    }
    else
        return _point[m][n];
}
// Mutator: Set the value at the m-th point and n-th coordinate
bool Polygon::setValue (double & value, unsigned int m, unsigned int n)
{
    if (m>=0 && m<_m && n>=0 && n<_n)
    {
        _point[m][n] = value;
        return true;
    }
    else
        return false;
}
