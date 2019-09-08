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
const long long INF = 0x3f3f3f3f;

///////////////////////////
const long long MAX_N=100001;
long long par[MAX_N];
long long ranks[MAX_N];
void init(long long n)
{
    for(long long i=0;i<n;i++)
    {
        par[i]=i;
        ranks[i]=0;
    }
}
long long find(long long x)
{
    if(par[x]==x)
        return x;
    else
        return par[x]=find(par[x]);
}
void unite(long long x,long long y)
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
bool same(long long x,long long y)
{
    return find(x)==find(y);
}

struct edge
{
    long long u,v,cost;
    edge(){}
    edge(long long _u,long long _v,long long _cost)
    {
        u=_u;v=_v;cost=_cost;
    }
    bool operator < (const edge &a) const
    {
        return cost > a.cost;
    }
};
priority_queue<edge> edges,used1,used2;
long long n,m,maxedge=0;
long long kruskal()
{
    init(n+1);
    long long sum=0;
    long long len=edges.size();
    edge tmp;
    for(long long i=0;i<len;++i)
    {
        tmp=edges.top();edges.pop();
        if(!same(tmp.u,tmp.v))
        {
            unite(tmp.u,tmp.v);
            sum+=tmp.cost;
            maxedge=max(maxedge,tmp.cost);
            used1.push(tmp);
        }
        else
        {
            used2.push(tmp);
        }
    }
    return sum;
}
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    long long u,v,w;
    for(long long i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        edges.push(edge{u,v,w});
    }
    long long nowsum=kruskal();
    long long fangan=0;
    nowsum-=maxedge;
    init(n+1);
    long long len=used1.size();
    edge tmp;
    for(long long i=0;i<len;++i)
    {
        tmp=used1.top();used1.pop();
        if(tmp.cost!=maxedge)
        {
            unite(tmp.u,tmp.v);
        }
        else
        {
            ++fangan;
        }
    }
    len=used2.size();
    for(long long i=0;i<len;++i)
    {
        tmp=used2.top();used2.pop();
        if(!same(tmp.u,tmp.v))
        {
            ++fangan;
        }
    }
    cout<<nowsum<<" "<<fangan;
    return 0;
}
