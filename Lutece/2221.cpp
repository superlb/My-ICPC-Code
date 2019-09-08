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

///////////////////////////
const long long MAX_V=250;
const long long INF=1ll << 60;
struct edge
{
    long long to,cap,rev;
};
vector<edge> G[MAX_V];
long long level[MAX_V];
long long iter[MAX_V];

void add_edge(long long from, long long to, long long cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

void bfs(long long s)
{
    memset(level,-1,sizeof(level));
    queue<long long> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty())
    {
        long long v=que.front();que.pop();
        for(long long i=0;i<G[v].size();++i)
        {
            edge e=G[v][i];
            if(e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

long long dfs(long long v,long long t,long long f)
{
    if(v==t)return f;
    for(long long &i=iter[v];i < G[v].size();++i)
    {
        edge &e=G[v][i];
        if(e.cap > 0 && level[v] < level[e.to])
        {
            long long d=dfs(e.to, t, min(f, e.cap));
            if(d > 0)
            {
                e.cap -=d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

long long max_flow(long long s,long long t)
{
    long long flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t] < 0)
        {
            return flow;
        }
        memset(iter,0,sizeof(iter));
        long long f;
        while((f = dfs(s, t ,INF)) > 0)
        {
            flow+=f;
        }
    }
}

////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,m,s,e,c;
    cin>>n>>m;
    for(long long i=0;i<m;++i)
    {
        cin>>s>>e>>c;
        add_edge(s,e,c);
    }
    cout<<max_flow(1,n)<<endl;
    return 0;
}
