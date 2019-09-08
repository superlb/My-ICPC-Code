#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long x, y;
}nodes[17];
long long g[17][17];
long long n, s;
const long long INF = 100000000000000ll;
long long dp[1 << 17][17];
long long solve(long long S, long long v)
{
	if (dp[S][v] >= 0)
	{
		return dp[S][v];
	}
	if (S == (1ll << n)-1)
	{
		return dp[S][v] = 0;
	}
	long long res = INF;
	for (int i = 0; i < n; ++i)
	{
		if (!(S >> i & 1))
		{
			res = min(res, solve(S | 1ll << i, i) + g[v][i]);
		}
	}
	return dp[S][v] = res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	fill(g[0],g[0]+17*17,INF);
	cin >> n >> s;
	for (long long i = 0; i < n; ++i)
	{
		cin >> nodes[i].x >> nodes[i].y;
	}
	for (long long i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			g[i][j] = abs(nodes[i].x - nodes[j].x) + abs(nodes[i].y - nodes[j].y);
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0,s-1);
	//system("pause");
	return 0;
}
