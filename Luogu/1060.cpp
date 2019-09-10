#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[25], b[25];
int dp(int nowm, int nown)
{
	if (nowm == m)return 0;
	if (a[nowm] > nown)
	{
		return dp(nowm + 1, nown);
	}
	else
	{
		return max(dp(nowm + 1, nown), dp(nowm + 1, nown - a[nowm]) + a[nowm] * b[nowm]);
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i] >> b[i];
	}
	cout << dp(0, n);
	//system("pause");
	return 0;
}
