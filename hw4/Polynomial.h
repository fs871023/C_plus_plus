#define NodePointer Node*
typedef int CoefType;// term in a polynomial
class Term
{
public:
    CoefType coef;
    int expo;
};
// node in a linked list
class Node
{
private:
    Term data;
    NodePointer next;
public:
    Node(CoefType, int, Node *);// node constructor
    friend class Polynomial;
};
// polynomial ADT
class Polynomial
{
private:
    NodePointer head; // pointing to the first dummy node
public:
    Polynomial (CoefType*, int*, int );// constructor
    ~Polynomial();// destructor
    void add (CoefType, int ); // add a term into the polynomial
    void differentiate();// differentiation
    const void printPolynomial() const;//print the polynomial
};
