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
int par[30];
int ranks[30];
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
    int t,n,q;
    char alp,alp2;
    while(cin>>t)
    {
        if(t==0)break;
        init(t+1);
        priority_queue<g> gs;
        for(int i=0;i<t-1;++i)
        {
            cin>>alp>>n;
            for(int j=0;j<n;++j)
            {
                cin>>alp2>>q;
                gs.push(g(alp-'A',alp2-'A',q));
            }
        }
        int sum=0;
        int len=gs.size();
        g linshi;
        for(int i=0;i<len;++i)
        {
            linshi=gs.top();gs.pop();
            if(!same(linshi.u,linshi.v))
            {
                unite(linshi.u,linshi.v);
                sum+=linshi.cost;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
