#include<iostream>
#include<fstream>
using namespace std;

class RingNode
{
public:
    char value;// value stored in the node
    RingNode* next;// pointer to the next RingNode
};

void print_the_ring(const RingNode* head, int size)//print the list
{
    for (int i=0; i<size; i++)
    {
        cout << head->value << endl;//print the list
        head = head->next;//go ahead to next node
    }
}

int read_recursively (const RingNode* head,ifstream& fin, RingNode*& current)
{
    char ch;
    fin.get(ch);//store the input to a char
    if (ch=='\n'||fin.eof())//if there is \n or EOF, return
    {
        current=head->next;//let the last one's next to head
        return 0;
    }
    else
    {
        current->next=new RingNode();//declare a new node
        current=current->next;//go ahead
        current->value=ch;//add it to last
        current->next=NULL;
    }

    return 1+read_recursively (head, fin, current);//count the amount of node
}
