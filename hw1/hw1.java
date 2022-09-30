public class hw1
{
    class test
    {
        private char c;
        private int _count;
        private _char_count next[];
    }
    public static void main(String[] args)
    {
        int i, j;
        char_count headptr, prev;
        headptr = NULL;
        prev = NULL;
        headptr= new char_count;//initialize headptr
        headptr->c=0;
        headptr->_count=0;
        headptr->next=NULL;
        for(i=1; i<args.length; i++)//put argv into char_count
        {
            for(j=0; j<length(args[i]); j++)
            {
                if(args[i][j]=='\0')//string end
                    break;
                prev=headptr;
                while(prev->next!=NULL && prev->c!=args[i][j])//檢查整個 linked list 來看是否有重複
                {
                    prev=prev->next;//keep going
                }
                if(prev->c==argv[i][j])//if same , count++
                {
                    prev->_count++;
                    continue;
                }
                else if(prev->next==NULL)//if there is no same one , add it in
                {
                    prev->next=new char_count();//declare a new struct
                    prev=prev->next;
                    prev->c=args[i][j];//add it to bottom
                    prev->_count=1;
                    prev->next=NULL;
                }
            }
        }
        prev=headptr->next;
        while(prev!=NULL)
        {
            cout<<(prev->c)<<"-"<<(prev->_count)<<endl;
            prev=prev->next;
        }
        return 0;
    }
}
