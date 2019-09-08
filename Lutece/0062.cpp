#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int l, m;
	int a, b;
	int sum = 0;
	int s[10001];
	scanf("%d %d", &l, &m);
	memset(s, 0, 10001 * sizeof(int));
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		for (; a <= b; ++a)
		{
			if (s[a] == 0)
			{
				s[a] = 1;
			}
		}
	}
	for (int i = 0; i <= l; ++i)
	{
		if (s[i] == 0)++sum;
	}
	printf("%d", sum);
	return 0;
}
