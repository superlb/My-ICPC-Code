#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,l, v;
	double time;
	int a;
	char b, c;
	double sum;
	double len;
	while (scanf("%d %d %d", &n, &l,&v) == 3)
	{
		if (n == 0 && l == 0 && v == 0)break;
		time = 0.0; sum = 0.0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %c %c",&a,&b,&c);
			if (c == 'W')
			{
				len = a;
			}
			else
			{
				len = l - a;
			}
			if (len / v > time)time = len / v;
			sum += len;
		}
		printf("%.2f %.2f\n", time, sum);
	}
	return 0;
}
