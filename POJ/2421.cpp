#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

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
struct g
{
    int u,v,cost;
    g(){}
    g(int _u,int _v,int _cost)
    {
        u=_u;v=_v;cost=_cost;
    }
    bool operator < (const g &a) const
    {
        return cost > a.cost;
    }
};
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,a,b;
    priority_queue<g> gs;
    cin>>n;
    init(n+1);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a;
            if(i==j)
            {
                continue;
            }
            else
            {
                gs.push(g(i,j,a));
            }
        }
    }
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b;
        unite(a-1,b-1);
    }
    int len=gs.size();
    int sum=0;
    g tmp;
    for(int i=0;i<len;++i)
    {
        tmp=gs.top();gs.pop();
        if(!same(tmp.u,tmp.v))
        {
            unite(tmp.u,tmp.v);
            sum+=tmp.cost;
        }
    }
    cout<<sum<<endl;
    return 0;
}
