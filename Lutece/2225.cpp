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
    int to,cap,rev;
};
const int MAX_V=20050;
int n,m;
int a[10001];
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

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

////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;++i)
    {
        add_edge(0,i,a[i]);
    }
    int c,k,pindao;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>c>>k;
        sum+=c;
        add_edge(m+1+i,m+n+2,c);
        for(int j=0;j<k;++j)
        {
            cin>>pindao;
            add_edge(pindao,m+1+i,a[pindao]);
        }
    }
    cout<<sum-max_flow(0,m+n+2)<<endl;
    return 0;
}
