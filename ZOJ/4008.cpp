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
int bit[200010],n,q,t,u,v,ans[200010];
inline int lowbit(int x)
{
    return x&-x;
}
void add(int x,int val)
{
    for(int i=x;i<=n;i+=lowbit(i))
        bit[i]+=val;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=bit[i];
    return res;
}
struct seg
{
    int l,r,kind,id;
}segs[400010];
bool cmp(const seg &a,const seg &b)
{
    if(a.r==b.r)
        return a.kind<b.kind;
    else
        return a.r<b.r;
}
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>q;
        for(int i=0;i<n-1;++i)
        {
            scanf("%d%d",&segs[i].l,&segs[i].r);
            if(segs[i].l>segs[i].r)
                swap(segs[i].l,segs[i].r);
            segs[i].kind=0;
        }
        for(int i=0;i<q;++i)
        {
            scanf("%d%d",&segs[i+n-1].l,&segs[i+n-1].r);
            if(segs[i+n-1].l>segs[i+n-1].r)
                swap(segs[i+n-1].l,segs[i+n-1].r);
            segs[i+n-1].kind=1;
            segs[i+n-1].id=i;
        }
        sort(segs,segs+n+q-1,cmp);
        memset(bit,0,sizeof(bit));
        u=0;
        for(int i=0;i<n+q-1;++i)
        {
            if(!segs[i].kind)
            {
                ++u;
                add(segs[i].l,1);
            }
            else
            {
                ans[segs[i].id]=(segs[i].r-segs[i].l+1) - (u - sum(segs[i].l-1));
            }
        }
        for(int i=0;i<q;++i)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
