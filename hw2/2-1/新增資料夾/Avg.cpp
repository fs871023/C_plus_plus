double Avg (int Array[ ], int N)//calculate average : sum/n
{
    float sum=0;
    for(int i=0;i<N;i++)
    {
        sum=sum+Array[i];
    }
    return sum/N;
}
