#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
long long sum[4*100010][50];
long long lazy[4*100010],status[4*100010];
long long a[100010],pre[100010];
void init()
{
    for(long long i=0;i<99971ll;++i)
    {
        pre[i]=i*i*i%99971ll;
    }
}
void pushup(long long v)
{
    for(long long i=0;i<48;++i)
    {
        sum[v][i]=(sum[2*v][(status[2*v]+i)%48]+sum[2*v+1][(status[2*v+1]+i)%48]) % 99971;
    }
    status[v]=0;
}
void pushdown(long long v)
{
    if(!lazy[v])return;
    lazy[2*v]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    status[2*v]=(status[2*v]+lazy[v])%48;
    status[2*v+1]=(status[2*v+1]+lazy[v])%48;
    lazy[v]=0;
}
void build(long long l,long long r,long long v)
{
    lazy[v]=status[v]=0;
    if(l==r)
    {
        sum[v][0]=a[l] % 99971;
        for(long long i=1;i<48;++i)
        {
            sum[v][i]=pre[ sum[v][i-1] ];
        }
        return;
    }
    long long m=(l+r)/2;
    build(l,m,2*v);
    build(m+1,r,2*v+1);
    pushup(v);
}
void update(long long l,long long r,long long lt,long long rt,long long v)
{
    if(lt<=l && r<=rt)
    {
        status[v] = (status[v]+1) % 48;
        ++lazy[v];
        return;
    }
    pushdown(v);
    long long m=(l+r)/2;
    if(lt<=m) update(l,m,lt,rt,2*v);
    if(rt>m) update(m+1,r,lt,rt,2*v+1);
    pushup(v);
}
long long query(long long l,long long r,long long lt,long long rt,long long v)
{
    if(lt<=l && r<=rt)
    {
        return sum[v][status[v]];
    }
    long long ans=0;
    pushdown(v);
    long long m=(l+r)/2;
    if(lt<=m) ans+=query(l,m,lt,rt,2*v);
    if(rt>m) ans+=query(m+1,r,lt,rt,2*v+1);
    pushup(v);
    return ans%99971;
}
long long t,n,q;
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(long long i=1;i<=n;++i)
        {
            scanf("%d",a+i);
        }
        long long d1,d2,d3;
        build(1,n,1);
        for(long long i=0;i<q;++i)
        {
            scanf("%d%d%d",&d1,&d2,&d3);
            if(d1==1)
            {
                update(1,n,d2,d3,1);
            }
            else if(d1==2)
            {
                printf("%d\n",query(1,n,d2,d3,1));
            }
        }
    }
    return 0;
}
