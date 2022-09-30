#include <iostream>
using namespace std;

#include "Polynomial.h"
Node::Node(CoefType co = 0, int ex = 0, Node * ptr = NULL)
{
    data.coef = co;
    data.expo = ex;
    next = ptr;
}
// constructor// c: pointer to an array of coefficients
// e: pointer to the corresponding exponents
// num: the number of elements in c (or e); num >= 0
Polynomial::Polynomial (CoefType* c = NULL, int* e = NULL, int num = 0)
{
    head=new Node;//create a dummy node
    head->next=new Node(c[0],e[0],NULL);//put first value to construct a polynomial
    for(int i=1; i<num; i++) //put value into Node*
    {
        add(c[i], e[i]);
    }
    cout<<"A polynomial is being created."<<endl;
}
// destructor
Polynomial::~Polynomial()// add a term into the polynomial
{
    Node* current=head;
    Node* tempptr;
    while (current->next!=NULL)
    {
        tempptr=current;//the node you want to delete
        current=current->next;//move forward, so we won't delete current, which cause us lost the nodes
        delete tempptr;//delete it
    }
    delete current;
    current=NULL;
    cout<<"A polynomial is being deleted."<<endl;
}
// adding a term to the polynomial with decreasing exponents
// c: the coefficient
// e: the exponent
void Polynomial::add (CoefType c, int e)
{
    Node * pre, *current;
    pre=head;
    current=head->next;//now situation
    while( current!=NULL && current->data.expo > e )//find the situation to add
    {
        //if the list is not end AND the exponent > e
        pre=current;
        current=current->next;//keep going...
    }
    if(current==NULL) // at the end of polynomial
    {
        // create a node with coefficient c and exponent e
        Node *n=new Node(c,e);
        pre->next=n;//adds a node to a polynomial object
    }
    else if(current->data.expo == e )//the exponent has already existed,
    {
        ////their coefficients will be added
        current->data.coef = current->data.coef +c;
        add the coefficient
    }
    else if(current->data.expo < e)//the exponential is between pre and current
    {
        Node *n=new Node(c,e);//
        pre->next=n;
        n->next=current;
    }
    current=pre->next;//check if coefficient is 0
    if(current->data.coef == 0)
    {
        pre->next=current->next;
        delete current;
    }
}
void Polynomial::differentiate()
{
    Node* pre;
    Node* current=head->next;
    while(current!=NULL)
    {
        if(current->data.expo==0)
        {
            pre->next=current->next;
            delete current;
            current=pre->next;
            continue;
        }
        (current->data.coef)=(current->data.coef) * (current->data.expo);
        -- (current->data.expo);
        pre=current;
        current=current->next;
    }
}
const void Polynomial::printPolynomial() const
{
    Node* current=head->next;
    while(current->next!=NULL)
    {
        cout<<current->data.coef<<"x^"<<current->data.expo;
        cout<<" + ";
        current=current->next;
    }
    cout<<current->data.coef<<"x^"<<current->data.expo;
    cout<<endl;
}
