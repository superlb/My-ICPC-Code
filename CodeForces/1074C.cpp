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
struct p
{
    int x,y;
}ps[300010];
int dist(p a,p b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    int pl,pr,pu,pd;
    int l=INF,r=-INF,u=-INF,d=INF;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>ps[i].x>>ps[i].y;
        if(ps[i].x<l)
        {
            l=ps[i].x;
            pl=i;
        }
        if(ps[i].x>r)
        {
            r=ps[i].x;
            pr=i;
        }
        if(ps[i].y>u)
        {
            u=ps[i].y;
            pu=i;
        }
        if(ps[i].y<d)
        {
            d=ps[i].y;
            pd=i;
        }
    }
    for(int k=3;k<=n;++k)
    {
        if(k==3)
        {
            int ans=0;
            for(int j=0;j<n;++j)
            {
                int tmp=dist(ps[j],ps[pl])+dist(ps[j],ps[pd])+dist(ps[pl],ps[pd]);
                ans=max(tmp,ans);
            }
            for(int j=0;j<n;++j)
            {
                int tmp=dist(ps[j],ps[pl])+dist(ps[j],ps[pu])+dist(ps[pl],ps[pu]);
                ans=max(tmp,ans);
            }
            for(int j=0;j<n;++j)
            {
                int tmp=dist(ps[j],ps[pr])+dist(ps[j],ps[pd])+dist(ps[pr],ps[pd]);
                ans=max(tmp,ans);
            }
            for(int j=0;j<n;++j)
            {
                int tmp=dist(ps[j],ps[pr])+dist(ps[j],ps[pu])+dist(ps[pr],ps[pu]);
                ans=max(tmp,ans);
            }
            cout<<ans<<" ";
        }
        else
        {
            cout<<2*(r-l+u-d)<<" ";
        }
    }
    return 0;
}
