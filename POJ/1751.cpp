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
using namespace std;

///////////////////////////
int par[10000];
int ranks[10000];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
      par[i]=i;
      ranks[i]=0;
    }
}
int find(int x)
{
    if(par[x]==x)
    {
      return x;
    }
    else
    {
      return par[x]=find(par[x]);
    }
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(ranks[x]<ranks[y])
    {
      par[x]=y;
    }
    else
    {
      par[y]=x;
      if(ranks[x]==ranks[y])ranks[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
struct edge
{
    int u,v,cost;
    edge(){}
    edge(int _u,int _v,int _cost)
    {
        u=_u;v=_v;cost=_cost;
    }
    bool operator < (const edge &a) const
    {
        return cost > a.cost;
    }
};
////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    int x[1000],y[1000];
    priority_queue<edge> edges;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            int dif=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            edges.push(edge(i,j,dif));
        }
    }
    int m,q,w;
    int now=0;
    cin>>m;
    init(n+1);
    for(int i=0;i<m;++i)
    {
        cin>>q>>w;
        if(!same(q,w))
        {
            unite(q,w);
            ++now;
        }
    }
    int len=edges.size();
    edge tmp;
    for(int i=0;i<len && now < n-1;++i)
    {
        tmp=edges.top();edges.pop();
        if(!same(tmp.u,tmp.v))
        {
            unite(tmp.u,tmp.v);
            ++now;
            cout<<tmp.u<<" "<<tmp.v<<endl;
        }
    }
    return 0;
}
