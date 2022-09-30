#include"ring.h"
int main()
{
    ifstream fin;
    fin.open("input.txt");//open file

    if(!fin)
        cout<<"open error"<<endl;

    RingNode* head;
    head=new RingNode();
    head->next=NULL;
    int total = read_recursively(head,fin, head);//implement a ring and record how many nodes
    print_the_ring(head, total);//print out

    fin.close();

    return 0;
}

