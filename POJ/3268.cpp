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
    int to,cost;
};
vector<edge> G1[1010];
vector<edge> G2[1010];
int d1[1010];
int d2[1010];
int n,m,x;
void dijkstra1(int s)
{
    priority_queue< pair<int,int> ,vector< pair<int,int> > , greater< pair<int,int> > > q;
    fill(d1+1,d1+n+1,INF);
    d1[s]=0;
    q.push(pair<int,int>(0,s));
    while(!q.empty())
    {
        pair<int,int> p=q.top();q.pop();
        int v=p.second;
        if(d1[v]<p.first)
            continue;
        int len=G1[v].size();
        for(int i=0;i<len;++i)
        {
            edge e=G1[v][i];
            if(d1[e.to]>d1[v]+e.cost)
            {
                d1[e.to]=d1[v]+e.cost;
                q.push(pair<int,int>(d1[e.to],e.to));
            }
        }

    }
}
void dijkstra2(int s)
{
    priority_queue< pair<int,int> ,vector< pair<int,int> > , greater< pair<int,int> > > q;
    fill(d2+1,d2+n+1,INF);
    d2[s]=0;
    q.push(pair<int,int>(0,s));
    while(!q.empty())
    {
        pair<int,int> p=q.top();q.pop();
        int v=p.second;
        if(d2[v]<p.first)
            continue;
        int len=G2[v].size();
        for(int i=0;i<len;++i)
        {
            edge e=G2[v][i];
            if(d2[e.to]>d2[v]+e.cost)
            {
                d2[e.to]=d2[v]+e.cost;
                q.push(pair<int,int>(d2[e.to],e.to));
            }
        }

    }
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>x;
    int u,v,w;
    for(int i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        G1[u].push_back(edge{v,w});
        G2[v].push_back(edge{u,w});
    }
    dijkstra1(x);
    dijkstra2(x);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(i==x) continue;
        ans=max(ans,d1[i]+d2[i]);
    }
    cout<<ans<<endl;
    return 0;
}
