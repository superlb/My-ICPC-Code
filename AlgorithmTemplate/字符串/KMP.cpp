//对模式串进行处理
void preKMP(string x,int m,int kmpNext[])
{
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    //next数组递推计算
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j]) j=kmpNext[j];
        if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
        else kmpNext[i]=j;
    }
}
int nexts[200010];
//x为主串，y为模式串
int KMP_Count(string x,string y)
{
    int i=0,j=0;
    int ans=0;
    int m=x.length(),n=y.length();
    preKMP(x,m,nexts);
    //匹配过程
    while(i<n)
    {
        while(j!=-1 && y[i]!=x[j]) j=nexts[j];
        i++;j++;
        if(j>=m)
        {
            ans++;
            j=nexts[j];
        }
    }
    return ans;
}




//C++风格重写
void preKMP(string x,vector<int> &kmpNext)
{
    int i = 0;
    int j = kmpNext[0] = -1;
    while (i < x.size())
    {
        while (j != -1 && x[i] != x[j])
            j = kmpNext[j];
        if (x[++i] == x[++j])
            kmpNext[i] = kmpNext[j];
        else
            kmpNext[i] = j;
    }
}
int KMP_Count(string x, string y)
{
    int i = 0, j = 0;
    int ans = 0;
    vector<int> next(x.size(),0);
    preKMP(x,next);
    while (i < y.size())
    {
        while (j != -1 && y[i] != x[j])
            j = nexts[j];
        i++;
        j++;
        if (j >= x.size())
        {
            ans++;
            j = nexts[j];
        }
    }
    return ans;
}
