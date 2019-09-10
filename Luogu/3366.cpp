#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u, v, cost;
}es[200000];
bool cmp(const edge& e1, const edge& e2)
{
	return e1.cost < e2.cost;
}
int par[5001];
int rank1[5001];
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rank1[i] = 0;
	}
}
int find(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank1[x] < rank1[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rank1[x] == rank1[y])rank1[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> es[i].u >> es[i].v >> es[i].cost;
	}
	sort(es, es + m, cmp);
	init(n+1);
	long long res = 0;
	for (int i = 0; i < m; ++i)
	{
		edge e = es[i];
		if (!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	cout << res;
	return 0;
}
