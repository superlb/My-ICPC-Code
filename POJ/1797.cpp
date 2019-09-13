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
const long long INF64 = 5e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
int ranks[1001];
int par[1001];
int find(int x)
{
    if(par[x]==x)return x;
    else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y)return;
    if(ranks[x]<ranks[y]) par[x]=y;
    else
    {
        par[y]=x;
        if(ranks[x]==ranks[y]) ranks[x]++;
    }
}
struct edge
{
    int u,v,w;
    bool operator < (const edge &e) const
    {
        return w<e.w;
    }
};
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,tot=1,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            par[i]=i;ranks[i]=0;
        }
        priority_queue<edge> q;
        int u,v,w;
        for(int i=0;i<m;++i)
        {
            cin>>u>>v>>w;
            q.push(edge{u,v,w});
        }
        int ans=0;
        for(int i=0;i<m;++i)
        {
            edge e = q.top();q.pop();
            ans=e.w;
            unite(e.u,e.v);
            if(find(1)==find(n))break;
        }
        cout<<"Scenario #"<<tot++<<":"<<endl;
        cout<<ans<<endl<<endl;
    }
    return 0;
}
