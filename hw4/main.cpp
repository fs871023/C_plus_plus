#include <iostream>
#include "Polygon.h"
#include "Polynomial.h"
using namespace std;
void PrintPoints ( Polygon p)
{
    for (unsigned int i=0; i<p.getNumOfPoints(); i++)
    {
        for (unsigned int j=0; j<p.getDimension(); j++)
            cout << p.getValue(i, j) <<" ";
        cout << endl;
    }
}
int main()
{
    Polygon p(3, 4);
    double k = 0;
    for (int i=0; i<p.getNumOfPoints(); i++)
        for (int j=0; j<p.getDimension(); j++)
        {
            k += 1;
            p.setValue(k, i, j);
        }
    PrintPoints(p);
    double* centroid = p.FindCentroid();
    for (int n=0; n<p.getDimension(); n++)
        cout << centroid[n]<<" ";
    cout << endl;

    int expo[]={1,-3,3,6,4,8,2,4,3,0,9,-1,5};//value of exponential
    int coef[]={12,-5,56,38,-35,7,0,2,-56,18,11,23,-1};//value of coefficient
    Polynomial polm(coef,expo,13);//construct a polynomial
    polm.printPolynomial();//print

    polm.differentiate();//differentiate
    polm.printPolynomial();

	polm.differentiate();//differentiate again
    polm.printPolynomial();

    return 0;
}
