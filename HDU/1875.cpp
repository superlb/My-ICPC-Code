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
    //ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    for(int nowt=0;nowt<t;++nowt)
    {
        int c;
        int x[100],y[100];
        priority_queue<edge> edges;
        cin>>c;
        init(c);
        for(int i=0;i<c;++i)
        {
            cin>>x[i]>>y[i];
        }
        int q;
        for(int i=0;i<c;++i)
        {
            for(int j=0;j<c;++j)
            {
                q=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                if(q>=100 && q<=1000000)
                {
                    edges.push(edge(i,j,q));
                }
            }
        }
        int len=edges.size();
        int now=0;
        double sum=0;
        edge e;
        for(int i=0;i<len;++i)
        {
            e=edges.top();edges.pop();
            if(!same(e.u,e.v))
            {
                unite(e.u,e.v);
                sum+=sqrt(e.cost);
                ++now;
            }
        }
        if(now==c-1)
        {
            printf("%.1f\n",sum*100.0);
        }
        else
        {
            cout<<"oh!"<<endl;
        }
    }
    return 0;
}
