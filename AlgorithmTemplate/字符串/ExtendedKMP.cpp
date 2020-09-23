void ExtendedKMP(char *a, char *b, int M, int N, int *Next, int *ret)
{
    int i, j, k;
    for(j = 0; i + j < M && a[j] == a[1+j]; ++j);
    Next[1] = j;
    k = 1;
    for(i = 2; i < M;++i)
    {
        int Len=k+Next[k],L=Next[i-k];
        if(L < Len - 1)
        {
            Next[i]=L;
        }
        else
        {
            for(j=max(0,Len-i);i+j<M && a[j]==a[i+j];++j);
            Next[i]=j;
            k=i;

        }
    }
    for(j = 0;j < N && j < M && a[j] == b[j];++j);
    ret[0]=j;
    k=0;
    for(i=1;i<N;++i)
    {
        int Len=k+ret[k],L=Next[i-k];
        if(L < Len - 1)
        {
            ret[i]=L;
        }
        else
        {
            for(j=max(0,Len-i);j<M && i+j<N && a[j]==b[i+j];++j);
            ret[i]=j;
            k=i;
        }
    }
}
