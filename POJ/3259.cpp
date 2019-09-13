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
#include <set>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
struct edge
{
    int from,to,cost;
};
edge es[10010];
int d[1010];
int V,E,m;
int u,v,w,tot=0;
bool find_negative_loop()
{
    memset(d,0,sizeof(d));
    for(int i=0;i<V;++i)
    {
        for(int j=0;j<tot;++j)
        {
            edge e=es[j];
            if(d[e.to] > d[e.from] + e.cost)
            {
                d[e.to] = d[e.from] + e.cost;
                if(i==V-1) return true;
            }
        }
    }
    return false;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>V>>E>>m;
        tot=0;
        for(int i=0;i<E;++i)
        {
            cin>>u>>v>>w;
            es[tot++]=edge{u,v,w};
            es[tot++]=edge{v,u,w};
        }
        for(int i=0;i<m;++i)
        {
            cin>>u>>v>>w;
            es[tot++]=edge{u,v,-w};
        }
        if(find_negative_loop())
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
