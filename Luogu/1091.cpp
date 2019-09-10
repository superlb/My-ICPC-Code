#include <bits/stdc++.h>
using namespace std;
int n;
int a[100], b[100],dp1[100],dp2[100];
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		b[n - i - 1] = a[i];
	}
	fill(dp1, dp1 + n, 10000);
	fill(dp2, dp2 + n, 10000);
	for (int i = 0; i < n; ++i)
	{
		*lower_bound(dp1,dp1+n,a[i])=a[i];
		a[i] = lower_bound(dp1, dp1 + n, 10000) - dp1;
	}
	for (int i = 0; i < n; ++i)
	{
		*lower_bound(dp2, dp2 + n, b[i]) = b[i];
		b[i] = lower_bound(dp2, dp2 + n, 10000) - dp2;
	}
	int maxnum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] + b[n - i - 1] - 1 > maxnum)
		{
			maxnum = a[i] + b[n - i - 1] - 1;
		}
	}
	cout << n - maxnum;
	//system("pause");
	return 0;
}
