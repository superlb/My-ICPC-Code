//树状数组
long long bit[MAXN],n;
inline long long lowbit(long long x)
{
    return x&-x;
}
//修改单点值，求前缀和
//改成差分数组，即可修改区间值，求单点值
void add(long long x,long long val)
{
    for(long long i=x; i<=n; i+=lowbit(i))
        bit[i]+=val;
}
long long sum(long long x)
{
    long long ret=0;
    for(long long i=x; i>0; i-=lowbit(i))
        ret+=bit[i];
    return ret;
}
//区间增减、区间求和
//修改区间：add(r,val);
//          if(l>1) add(l-1,-val);
//查询区间：sum(r)-sum(l-1);
long long bit1[MAXN],bit2[MAXN],n;
void add(long long x,long long val)
{
    for(long long i=x; i>0; i-=lowbit(i))
        bit1[i]+=val;
    for(long long i=x; i<=n; i+=lowbit(i))
        bit2[i]+=x*val;
}
long long sum(long long x)
{
    if(!x)
        return 0;
    long long ret1=0,ret2=0;
    for(long long i=x; i<=n; i+=lowbit(i))
        ret1+=bit1[i];
    for(long long i=x-1; i>0; i-=lowbit(i))
        ret2+=bit2[i];
    return ret1*x+ret2;
}
//最值
void modify(long long x,long long val)
{
    num[x]=val;
    for(long long i=x; i<=n; i+=lowbit(i))
    {
        bit[i]=max(bit[i],val);
        for(int j=1; j<lowbit(i); j<<=1)
            bit[i]=max(bit[i],bit[i-j]);
    }
}
long long query(long long L,long long R)
{
    int ret=num[R];
    while(true)
    {
        ret=max(ret,num[R]);
        if(L==R)break;
        for(R-=1; R-L>=lowbit(R); R-=lowbit(R))
            ret=max(ret,bit[R]);
    }
    return ret;
}
