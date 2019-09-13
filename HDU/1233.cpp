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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;

/////////////////////////
int par[101];
int ranks[101];
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
        return x;
    else
        return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);y=find(y);
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
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        init(n+1);
        priority_queue<edge> edges;
        int u,v,w;
        for(int i=0;i<n*(n-1)/2;++i)
        {
            cin>>u>>v>>w;
            edges.push(edge(u,v,w));
        }
        int sum=0;
        for(int i=0;i<n-1;)
        {
            edge tmp=edges.top();edges.pop();
            if(!same(tmp.u,tmp.v))
            {
                unite(tmp.u,tmp.v);
                sum+=tmp.cost;
                ++i;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
