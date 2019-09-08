#include <cstdio>
#include <cmath>
int main()
{
	int t;
	int n;
	long long sum;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d",&n);
		sum = 5;
		while (n > 1)
		{
			sum *= 3;
			n--;
		}
		printf("Case #%d: %lld\n", i+1 ,sum);
	}
	return 0;
}
