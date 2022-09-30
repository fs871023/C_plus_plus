int Large (int Array[ ], int N)//find largest
{
    int i;
    int Max=0;
    for(i=0;i<N;i++)
    {
        if(Array[i]>Max)
            Max=Array[i];//replace with the larger one
    }
    return Max;
}
