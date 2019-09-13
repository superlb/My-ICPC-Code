#include <iostream>
#include <queue>
using namespace std;
int par[105];
int ranks[105];
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
    bool operator <(const g &a) const
    {
        return cost>a.cost;
    }
};
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,a,b,c;
    while(cin>>n)
    {
        if(n==0)break;
        cin>>k;
        init(n+1);
        priority_queue<g> qwe;
        for(int i=0;i<k;++i)
        {
            cin>>a>>b>>c;
            qwe.push(g(a,b,c));
        }
        int sum=0,now=0;
        g asd;
        if(k)
        {
            asd=qwe.top();qwe.pop();
        }
        while(now!=n-1 && k)
        {
            while(same(asd.u,asd.v))
            {
                asd=qwe.top();qwe.pop();
            }
            sum+=asd.cost;
            unite(asd.u,asd.v);
            asd=qwe.top();qwe.pop();
            ++now;
        }
        cout<<sum<<endl;
    }
    return 0;
}
