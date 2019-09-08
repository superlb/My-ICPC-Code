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
priority_queue<edge> edges;
const int MAX_N=1001;
int par[MAX_N];
int ranks[MAX_N];
void init(int n)
{
    for(int i=0;i<=n;i++)
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
vector<int> mstcost;
int kruskal(int n)
{
    init(n);
    int sum=0;
    edge tmp;
    for(int i=0;i<n-1;)
    {
        tmp=edges.top();edges.pop();
        if(!same(tmp.u,tmp.v))
        {
            unite(tmp.u,tmp.v);
            sum+=tmp.cost;
            mstcost.push_back(tmp.cost);
            ++i;
        }
    }
    return sum;
}
////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k,u,v,w;
    cin>>n>>m>>k;
    for(int i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        edges.push(edge(u,v,w));
    }
    int sum=kruskal(n);
    for(int i=0;i<k-1;++i)
    {
        sum-=mstcost[n-2-i];
    }
    cout<<sum<<endl;
    return 0;
}
