#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
const int INF = 1000000001;
struct edge
{
	int to, cost;
};
vector<edge> G[MAXN];
int father[MAXN][20];
int minnum[MAXN][20];
int depth[MAXN];
void dfs(int v,int _father,int _cost,int dp)
{
	father[v][0] = _father; minnum[v][0] = _cost; depth[v] = dp;
	int len = G[v].size();
	for (int i = 0; i < len; i++)
	{
		if (G[v][i].to != _father)
		{
			dfs(G[v][i].to,v, G[v][i].cost,dp+1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, q,a,b,c,nowmin;
	edge linshibian;
	cin >> n >> q;
	for (int i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		linshibian.to = b;
		linshibian.cost = c;
		G[a].push_back(linshibian);
		linshibian.to = a;
		G[b].push_back(linshibian);
	}
	dfs(n/2,-1,INF,1);
	for (int k = 1; k < 20; ++k)
	{
		for (int i = 1; i <= n; i++)
		{
			father[i][k] = father[father[i][k - 1]][k - 1];
			minnum[i][k] = min(minnum[i][k-1], minnum[father[i][k - 1]][k-1]);
		}
	}
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;
		nowmin = INF;
		if (a == b)nowmin = 0;
		if (depth[a] > depth[b])swap(a, b);
		for (int k = 19; depth[b] > depth[a]; --k)
		{
			if ((depth[b] - depth[a]) >> k & 1)
			{
				nowmin = min(nowmin, minnum[b][k]);
				b = father[b][k];
			}
		}
		if (a != b)
		{
			for (int k = 19; k >= 0; --k)
			{
				if (father[a][k] != father[b][k])
				{
					nowmin = min(nowmin, min(minnum[a][k], minnum[b][k]));
					a = father[a][k];
					b = father[b][k];
				}
			}
			nowmin = min(nowmin, min(minnum[a][0], minnum[b][0]));
		}
		cout << nowmin << endl;
	}
	return 0;
}
