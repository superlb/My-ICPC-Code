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
const long long INF = 1ll << 60;

///////////////////////////
const long long MAXV=100050;
long long used[MAXV];

vector<long long> unused;
long long father[MAXV][20];
long long depth[MAXV];
long long lca_d[MAXV];

struct edge
{
    long long to,cost;
};
long long V;
vector<edge> G[MAXV];
long long d[100][MAXV];

//////////////
void dfs(long long v,long long _father,long long _cost,long long dp)
{
	father[v][0] = _father; lca_d[v]=_cost;depth[v] = dp;++used[v];
	long long len = G[v].size();
	for (long long i = 0; i < len; i++)
	{
		if (G[v][i].to != _father)
		{
		    if(used[G[v][i].to] == 0)
            {
                dfs(G[v][i].to, v, lca_d[v]+G[v][i].cost, dp+1);
            }
		    else
            {
                unused.push_back(v);
                unused.push_back(G[v][i].to);
            }
		}
	}
}
void lca_init()
{
    dfs(1,0,0,1);
	for (long long k = 1; k < 20; ++k)
	{
		for (long long i = 1; i <= V; i++)
		{
			father[i][k] = father[father[i][k - 1]][k - 1];
		}
	}
}
long long lca(long long a,long long b)
{
    if (a == b)return father[a][0];
    if (depth[a] > depth[b])swap(a, b);
    for (long long k = 19; depth[b] > depth[a]; --k)
    {
        if ((depth[b] - depth[a]) >> k & 1)
        {
            b = father[b][k];
        }
    }
    if (a != b)
    {
        for (long long k = 19; k >= 0; --k)
        {
            if (father[a][k] != father[b][k])
            {
                a = father[a][k];
                b = father[b][k];
            }
        }
        return father[a][0];
    }
    else
    {
        return a;
    }
}
///////////


void dijkstra(long long s,long long id)
{
    priority_queue< pair<long long,long long> , vector< pair<long long,long long> > ,greater< pair<long long,long long> > > q;
    fill(d[id],d[id]+V+1,INF);
    d[id][s]=0;
    q.push( pair<long long,long long>(0,s) );
    while(!q.empty())
    {
        pair<long long,long long> p=q.top();
        q.pop();
        long long v=p.second;
        if(d[id][v]<p.first)
            continue;
        long long len=G[v].size();
        for(long long i=0;i<len;++i)
        {
            edge e=G[v][i];
            if(d[id][e.to] > d[id][v] + e.cost)
            {
                d[id][e.to] = d[id][v] + e.cost;
                q.push(pair<long long,long long>(d[id][e.to],e.to));
            }
        }
    }
}

////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    memset(used,0,sizeof(used));
    lca_d[0]=0;
    long long m,u,v,w;
    cin>>V>>m;
    for(long long i=0;i<m;++i)
    {
        cin>>u>>v>>w;
        G[u].push_back((edge){v,w});
        G[v].push_back((edge){u,w});
    }
    lca_init();
    sort(unused.begin(),unused.end());
    long long len=unique(unused.begin(),unused.end()) - unused.begin();
    for(long long i=0;i<len;++i)
    {
        dijkstra(unused[i],i);
    }
    long long t,sum=0,last=1,ans,linshi;
    cin>>t;
    for(long long i=0;i<t;++i)
    {
        cin>>linshi;
        ans=lca_d[last]+lca_d[linshi]-2*lca_d[lca(last,linshi)];
        for(long long j=0;j<len;++j)
        {
            ans=min(d[j][last]+d[j][linshi],ans);
        }
        sum+=ans;
        last=linshi;
    }
    cout<<sum<<endl;
    return 0;
}
