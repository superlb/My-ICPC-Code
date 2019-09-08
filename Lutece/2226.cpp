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
struct edge
{
    int from,to,cost;
};
edge es[5001];
int d[1001];
int cnt[1001];
int n,m,tot=0;
int o,a,b;
bool is=true;
void shortest_path(int s)
{
    for(int i=0;i<=n;++i)
    {
        d[i]=0;
        cnt[i]=0;
    }
    d[s]=1;
    while(true)
    {
        bool update=false;
        for(int i=0;i<tot;++i)
        {
            edge e=es[i];
            if(d[e.from] != 0 && d[e.to] < d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                update=true;
                if(e.from)
                {
                    ++cnt[e.from];
                    if(cnt[e.from] > n/2)
                    {
                        is=false;
                        update=false;
                        break;
                    }
                }
            }
        }
        if(!update)
            break;
    }
}
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        es[tot++]=edge{0,i,0};
    }
    for(int i=0;i<m;++i)
    {
        cin>>o>>a>>b;
        if(o==1)
        {
            es[tot++]=edge{b,a,1};
        }
        else if(o==2)
        {
            es[tot++]=edge{a,b,1};
        }
        else if(o==3)
        {
            es[tot++]=edge{b,a,0};
            es[tot++]=edge{a,b,0};
        }
    }
    shortest_path(0);
    if(is)
    {
        int sum=0;
        for(int i=1;i<=n;++i)
        {
            sum+=d[i];
        }
        cout<<sum<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}
