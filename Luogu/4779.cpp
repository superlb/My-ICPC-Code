#include<bits/stdc++.h>
using namespace std;
const int MAXV = 100001;
const int INF = 2147483647;
struct edge
{
	int to, cost;
};
int V,m,start,u,v,lon;
vector<edge> G[MAXV];
int d[MAXV];
void dijkstra(int s)
{
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	fill(d, d + V + 1, INF);
	d[s] = 0;
	q.push(pair<int, int>(0, s));
	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();
		int v = p.second;
		if (d[v] < p.first)
			continue;
		int len = G[v].size();
		for (int i = 0; i < len; ++i)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				q.push(pair<int, int>(d[e.to], e.to));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> V >> m >> start;
	edge linshi;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> lon;
		linshi.to = v;
		linshi.cost = lon;
		G[u].push_back(linshi);
	}
	dijkstra(start);
	for (int i = 1; i <= V; ++i)
	{
		cout << d[i] << " ";
	}
	//system("pause");
	return 0;
}
