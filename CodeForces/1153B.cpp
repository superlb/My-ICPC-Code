#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, m, h;
	int qwe[100][100];
	int q[100],w[100];
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		cin >> q[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> qwe[i][j];
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (qwe[i][j] == 1)
			{
				qwe[i][j] = q[j];
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (qwe[j][i] > w[j])
			{
				qwe[j][i] = w[j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			cout << qwe[i][j]<<" ";
		}
		cout << qwe[i][m - 1] << endl;
	}
	return 0;
}
