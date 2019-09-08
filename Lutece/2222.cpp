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
const long long INF = 1LL << 60;

///////////////////////////
const long long MAXV=1501;
struct edge
{
    long long to,cost;
};
long long V,k;
vector<edge> G[MAXV];
vector<edge> G2[MAXV];
long long d[MAXV];
struct node
{
    long long to,cost;
    bool operator < (const node &a) const
    {
        return a.cost + d[a.to] < cost + d[to];
    }
};

void dijkstra(long long s)
{
    priority_queue< pair<long long,long long> , vector< pair<long long,long long> > ,greater< pair<long long,long long> > > q;
    fill(d,d+V+1,INF);
    d[s]=0;
    q.push( pair<long long,long long>(0,s) );
    while(!q.empty())
    {
        pair<long long,long long> p=q.top();
        q.pop();
        long long v=p.second;
        if(d[v]<p.first)
            continue;
        long long len=G[v].size();
        for(long long i=0;i<len;++i)
        {
            edge e=G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push(pair<long long,long long>(d[e.to],e.to));
            }
        }
    }
}

long long bfs(long long s,long long t)
{
    priority_queue<node> q;
    q.push((node){s,0});
    node n;
    long long len;
    while(!q.empty())
    {
        n=q.top();q.pop();
        if(n.to == t)
        {
            --k;
            if(k==0)
            {
                return n.cost;
            }
        }
        len = G2[n.to].size();
        for(long long i=0;i<len;++i)
        {
            q.push((node){G2[n.to][i].to,G2[n.to][i].cost+n.cost});
        }
    }
    return -1;
}
////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long m,u,v,w,s,t;
    cin>>V>>m>>k;
    cin>>s>>t;
    for(long long i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        G2[u].push_back((edge){v,w});
        G[v].push_back((edge){u,w});
    }
    dijkstra(t);
    if(d[s]==INF)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<bfs(s,t)<<endl;
    }
    return 0;
}
