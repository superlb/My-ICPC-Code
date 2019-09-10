#include<bits/stdc++.h>
using namespace std;
int a[101], v[101][10001];
int n, m;
int main()
{
	ios::sync_with_stdio(false);
	memset(v, 0, sizeof(v));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++)
	{
		v[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; j++)
		{
			v[i][j] += v[i - 1][j];
			if (j >= a[i])
			{
				v[i][j] += v[i - 1][j - a[i]];
			}
		}
	}
	cout << v[n][m];
	//system("pause");
	return 0;
}
