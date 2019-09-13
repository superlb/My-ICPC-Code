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
const int INF = 0x3f3f3f3f;

///////////////////////////
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
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y,w;
        priority_queue<edge> edges,used1,used2;
        cin>>n>>m;
        init(n+1);
        for(int i=0;i<m;++i)
        {
            cin>>x>>y>>w;
            edges.push(edge(x,y,w));
        }
        int maxedge=0;
        int sum=0;
        int len=edges.size();
        for(int i=0;i<len;++i)
        {
            edge tmp=edges.top();edges.pop();
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
        len=used1.size();
        init(n+1);
        for(int i=0;i<len;++i)
        {
            edge tmp=used1.top();used1.pop();
            if(tmp.cost!=maxedge)
            {
                unite(tmp.u,tmp.v);
            }
        }
        len=used2.size();
        bool is=true;
        for(int i=0;i<len;++i)
        {
            edge tmp=used2.top();used2.pop();
            if(tmp.cost==maxedge && !same(tmp.u,tmp.v))
            {
                is=false;
                break;
            }
        }
        if(is)
        {
            cout<<sum<<endl;
        }
        else
        {
            cout<<"Not Unique!"<<endl;
        }
    }
    return 0;
}
