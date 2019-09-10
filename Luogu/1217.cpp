#include <iostream>
#include <stdio.h>
using namespace std;
bool isprime(long pri)
{
	if (pri % 3 == 0)return false;
	if (pri % 5 == 0)return false;
	if (pri % 7 == 0)return false;
	if (pri % 11 == 0)return false;
	if (pri % 13 == 0)return false;
	if (pri % 17 == 0)return false;
	if (pri % 19 == 0)return false;
	if (pri % 23 == 0)return false;
	if (pri % 29 == 0)return false;
	for (int j = 31; j < pri/29; j+=2)
	{
		if (pri%j == 0)return false;
	}
	return true;
}
int main()
{
	long a, b,b1;
	int k = 1;
	long linshi;
	cin >> a >> b;
	b1 = b;
	while ( b1/10 >=1 )
	{
		b1 /= 10;
		++k;
	}
	if (a<=5&&b>=5)
	{
		printf("5\n");
	}
	if (a <= 7&&b>=7)
	{
		printf("7\n");
	}
	if (a <= 11&&b>=11)
	{
		printf("11\n");
	}
	if (k > 2 && a < 1000)
	{
		for (int d1 = 1; d1 <= 9; d1 += 2)
		{
			for (int d2 = 0; d2 <= 9; ++d2)
			{
				linshi = d1 * 100 + d2 * 10 + d1;
				if (linshi > b || linshi < a)
				{
					continue;
				}
				else
				{
					if (isprime(linshi))
					{
						printf("%d\n", linshi);
					}
				}
			}
		}
	}
	if (k > 4 && a < 100000)
	{
		for (int d1 = 1; d1 <= 9; d1 += 2)
		{
			for (int d2 = 0; d2 <= 9; ++d2)
			{
				for (int d3 = 0; d3 <= 9; ++d3)
				{
					linshi = d1 * 10000 + d2 * 1000  + d3 * 100 + d2 * 10 + d1;
					if (linshi > b || linshi < a)
					{
						continue;
					}
					else
					{
						if (isprime(linshi))
						{
							printf("%d\n", linshi);
						}
					}
				}
			}
		}
	}
	if (k > 6 && a < 10000000)
	{
		for (int d1 = 1; d1 <= 9; d1 += 2)
		{
			for (int d2 = 0; d2 <= 9; ++d2)
			{
				for (int d3 = 0; d3 <= 9; ++d3)
				{
					for (int d4 = 0; d4 <= 9; ++d4)
					{
						linshi = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
						if (linshi > b || linshi < a)
						{
							continue;
						}
						else
						{
							if (isprime(linshi))
							{
								printf("%d\n", linshi);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
