#include <cstdio>
long long mod_pow(long long x, long long n, long long mod)
{
	long long res = 1;
	while (n > 0)
	{
		if (n & 1)res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
int main()
{
	int t;
	long long a, b;
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld%lld", &a, &b);
		printf("%.4lld\n",mod_pow(a,b,10000));
	}
	return 0;
}
