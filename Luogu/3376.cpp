// luogu-judger-enable-o2
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
const long long MOD=1000000007ll;
/////////////////////////
struct edge
{
    int to,cap,rev;
};
vector<edge> G[10010];
int level[10010];
int iter[10010];
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();que.pop();
        for(int i=0;i<G[v].size();++i)
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
int dfs(int v,int t,int f)
{
    if(v==t)return f;
    for(int &i=iter[v];i < G[v].size();++i)
    {
        edge &e=G[v][i];
        if(e.cap > 0 && level[v] < level[e.to])
        {
            int d=dfs(e.to, t, min(f, e.cap));
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
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t] < 0)
        {
            return flow;
        }
        memset(iter,0,sizeof(iter));
        int f;
        while((f = dfs(s, t ,INF)) > 0)
        {
            flow+=f;
        }
    }
}

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,s,t,u,v,w;
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    cout<<max_flow(s,t)<<endl;
    return 0;
}
