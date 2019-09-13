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
int par[500];
int ranks[500];
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
    //ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    for(int nowt=0;nowt<t;++nowt)
    {
        int s,p;
        int x[500],y[500];
        priority_queue<edge> edges;
        cin>>s>>p;
        for(int i=0;i<p;++i)
        {
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<p;++i)
        {
            for(int j=0;j<p;++j)
            {
                int q=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                edges.push(edge(i,j,q));
            }
        }
        int len=edges.size();
        vector<int> v;
        edge e;
        init(p);
        for(int i=0;i<len;++i)
        {
            e=edges.top();edges.pop();
            if(!same(e.u,e.v))
            {
                unite(e.u,e.v);
                v.push_back(e.cost);

            }
        }
        printf("%.2f\n",sqrt((double)v[p-s-1]));
    }
    return 0;
}
