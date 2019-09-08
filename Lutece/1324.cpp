#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	long long n, q, t, p, x;
	long long num[100001];
	long long sum;
	memset(num, 0, sizeof(num));
	scanf("%lld%lld", &n, &q);
	for (long long i = 0; i < q; i++)
	{
		sum = 0;
		scanf("%lld%lld%lld", &t, &p, &x);
		if (t == 1)
		{
			num[p] += x;
		}
		else if (t == 2)
		{
			for (long long j = p; j <= x; j++)
			{
				if (num[j] > sum)sum = num[j];
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}
