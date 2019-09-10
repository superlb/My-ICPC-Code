#include <bits/stdc++.h>
using namespace std;
int t, m;
int tim[10001], v[10001];
int dp[100001];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> tim[i] >> v[i];
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = tim[i]; j <= t; ++j)
		{
			dp[j] = max(dp[j],dp[j-tim[i]]+v[i]);
		}
	}
	cout << dp[t];
	//system("pause");
	return 0;
}
