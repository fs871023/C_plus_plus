double AvgN (int Array[ ], int N)//calculate negative average : sum/n
{
    float sumN=0;
    int countN=0;
    for(int i=0;i<N;i++)
    {
        if(Array[i]<0)
        {
            sumN=sumN+Array[i];
            countN++;
        }
    }
    return sumN/countN;
}
