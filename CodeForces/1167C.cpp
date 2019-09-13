#include <bits/stdc++.h>
using namespace std;
int par[500001];
int ranks[500001];
int pare1[500001] = { 0 };
int pare2[500001] = { 0 };
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		ranks[i] = 0;
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
	if (ranks[x] < ranks[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (ranks[x] == ranks[y])ranks[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int n, m,k,a1,a2;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	init(n+1);
	for (int i = 0; i < m; ++i)
	{
		cin >> k;
		if (k)
		{
			cin >> a1;
			for (int j = 1; j < k; ++j)
			{
				cin >> a2;
				unite(a1, a2);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		pare1[i] = find(i);
		++pare2[pare1[i]];
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << pare2[pare1[i]] << " ";
	}
	//system("pause");
	return 0;
}
