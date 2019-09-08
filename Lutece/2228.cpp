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
int par[1000];
int ranks[1000];
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
    int u,v;
    double height,dis,num;
    edge(){}
    edge(int _u,int _v,double _height,double _dis)
    {
        u=_u;v=_v;height=_height;dis=_dis;
    }
}edges[500005];
bool cmp(const edge &a,const edge &b)
{
    return a.num<b.num;
}
int x[1000],y[1000],z[1000];
int n,tot=0,pos;
double k,k0=1.0,hsum,dsum;
void diedai()
{
    while(1)
    {
        k=k0;hsum=0.0;dsum=0.0;pos=0;
        init(n);
        for(int i=0;i<tot;++i)
        {
            edges[i].num=edges[i].height-k*edges[i].dis;
        }
        sort(edges,edges+tot,cmp);
        for(int i=0;i<n-1;)
        {
            if(same(edges[pos].u,edges[pos].v))
            {
                ++pos;continue;
            }
            else
            {
                unite(edges[pos].u,edges[pos].v);
                hsum+=edges[pos].height;
                dsum+=edges[pos].dis;
                ++i;++pos;
            }
        }
        k0=hsum/dsum;
        if(fabs(k-k0)<0.000001)
            break;
    }
}
////////

int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            edges[tot++]=edge(i, j, (double)abs(z[i]-z[j]), sqrt( (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) ) );
        }
    }
    diedai();
    printf("%.3f",k0);
    return 0;
}
