#include <bits/stdc++.h>
using namespace std;
int a[1000001],b[1000001];
int dp1[1000001],dp2[1000001];
int result1[1000001], result2[1000001];
int search1(int x, int l, int r)
{
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (x > dp1[m])
			l = m + 1;
		else
			r = m - 1;
	}
	return l;
}
int search2(int x, int l, int r)
{
	int m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (x > dp2[m])
			l = m + 1;
		else
			r = m - 1;
	}
	return l;
}
void DP1(int n)
{
	int len = 1;
	dp1[1] = a[1];
	result1[1] = 1;
	for (int i = 2; i <= n;++i)
	{
		if (a[i] > dp1[len])
		{
			dp1[++len] = a[i];
		}
		else
		{
			dp1[search1(a[i], 1, len)] = a[i];
		}
		result1[i] = len;
	}
}
void DP2(int n)
{
	int len = 1;
	dp2[1] = b[1];
	result2[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (b[i] > dp2[len])
		{
			dp2[++len] = b[i];
		}
		else
		{
			dp2[search2(b[i], 1, len)] = b[i];
		}
		result2[i] = len;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		b[n - i + 1] = a[i];
	}
	DP1(n); DP2(n);
	int maxnum = 1;
	for (int i = 0; i < n; ++i)
	{
		if (result1[i] == result2[n - i + 1] && result1[i] * 2 - 1 > maxnum)
		{
			maxnum = result1[i] * 2 - 1;
		}
	}
	cout << maxnum;
	system("pause");
	return 0;
}
