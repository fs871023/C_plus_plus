double AvgP (int Array[ ], int N)//calculate positive average : sum/n
{
    float sumP=0;
    int countP=0;
    for(int i=0;i<N;i++)
    {
        if(Array[i]>0)
        {
            sumP=sumP+Array[i];
            countP++;
        }
    }
    return sumP/countP;
}
