#include <cstdio>
#include <cstring>
int qwe[2001][2001];
int main()
{
	int n, m, q, a, b;
	int num[2001];
	int is[101];
	int sum;
	memset(qwe, 0, sizeof(qwe));
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&num[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &a, &b);
		if (qwe[a][b] != 0)
		{
			sum = qwe[a][b];
		}
		else
		{
			sum = 0;
			memset(is, 0, sizeof(is));
			for (int j = a; j <= b; ++j)
			{
				if (is[num[j]] == 0)
				{
					is[num[j]]++;
					sum++;
					if (sum == m)break;
				}
			}
			qwe[a][b] = sum;
		}
		printf("%d\n",sum);
	}
	return 0;
}
