#include <iostream>
using std::cout;
using std::endl;
typedef struct _char_count
{
    char c;
    int _count;
    struct _char_count *next;
} char_count;
int main (int argc, char **argv)
{
    int i, j;
    char_count *headptr, *prev;
    prev = NULL;
    headptr= new char_count;//initialize headptr
    headptr->c=0;
    headptr->_count=0;
    headptr->next=NULL;
    for(i=1; i<argc; i++)//put argv into char_count
    {
        for(j=0; j<20; j++)
        {
            if(argv[i][j]=='\0')//string end
                break;
            prev=headptr;//start from head
            while(prev->next!=NULL && prev->c!=argv[i][j])//check whole linked list to see if same
            {
                prev=prev->next;//keep going
            }
            if(prev->c==argv[i][j])//if same , count++
            {
                prev->_count++;
                continue;
            }
            else if(prev->next==NULL)//if there is no same one , add it in to list
            {
                prev->next=new char_count();//declare a new char_count
                prev=prev->next;//go ahead
                prev->c=argv[i][j];//add it to last
                prev->_count=1;
                prev->next=NULL;
            }
        }
    }
    prev=headptr->next;//start from head
    while(prev!=NULL)
    {
        cout<<(prev->c)<<"-"<<(prev->_count)<<endl;//print whole list
        prev=prev->next;
    }
    return 0;
}
