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
int par[100];
int ranks[100];
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
    int t;
    while(cin>>t)
    {
        int x;
        priority_queue<edge> edges;
        for(int i=0;i<t;++i)
        {
            for(int j=0;j<t;++j)
            {
                cin>>x;
                edges.push(edge(i,j,x));
            }
        }
        int len=edges.size();
        int sum=0;
        edge e;
        init(t);
        for(int i=0;i<len;++i)
        {
            e=edges.top();edges.pop();
            if(!same(e.u,e.v))
            {
                unite(e.u,e.v);
                sum+=e.cost;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
