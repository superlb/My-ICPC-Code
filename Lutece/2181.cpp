#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

///////////////////////////
struct meizi
{
    long long v,w,h;
}meizis[10001];
bool cmp(const meizi &a,const meizi &b)
{
    return a.h<b.h;
}
long long n,m,k,x,y;
long long a,b,c,d;
long long dp[10001];
long long ans=0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,0,sizeof(dp));
    cin>>n>>m>>k>>x>>y;
    for(long long i=0;i<n;++i)
    {
        cin>>a>>b>>c>>d;
        meizis[i].v=a;
        if(c - b > 0)
        {
            meizis[i].w = ( c - b ) * y;
        }
        else
        {
            meizis[i].w = 0;
        }
        if(d - k > 0)
        {
            meizis[i].h = ( d - k ) * x;
        }
        else
        {
            meizis[i].h = 0;
        }
    }
    stable_sort(meizis,meizis+n,cmp);
    for(long long i=0;i<n;++i)
    {
        for(long long j = m-meizis[i].h;j>=meizis[i].w;--j)
        {
            dp[j]=max(dp[j],dp[j-meizis[i].w]+meizis[i].v);
            ans=max(ans,dp[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
