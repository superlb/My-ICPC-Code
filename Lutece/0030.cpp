#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 10000000
#define N 102
int map[N][N];
int main()
{
	int n, m, a, b, c;
	int dis[N];
	int f[N];
	while (scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0)break;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = INF;
			}
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			a--; b--;
			map[a][b] = map[b][a] = c;
		}
		for (int i = 0; i < n; i++)dis[i] = map[0][i];
		dis[0] = 0; f[0] = 1;
		for (int i = 0; i < n - 1; i++)
		{
			a = -1;
			b = INF;
			for (int j = 1; j < n - 1; ++j)
			{
				if (f[j] == 0 && dis[j] < b)
				{
					b = dis[j];
					a = j;
				}
			}
			if (a == -1)break;
			if (a == n - 1)break;
			f[a] = 1;
			for (int j = 1; j < n; j++)
			{
				if ((f[j]==0) && (b+map[a][j]<dis[j]))
				{
					dis[j] = b + map[a][j];
				}
			}
		}
		if (dis[n - 1] >= INF)printf("Impossible\n");
		else printf("%d\n", dis[n - 1]);
	}
	return 0;
}
