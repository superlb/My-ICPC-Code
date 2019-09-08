#include <cstdio>
int main()
{
	int a, b,c;
	while (scanf("%d%d", &a, &b) == 2)
	{
		if (a == 0 && b == 0)break;
		if (a % 3 == 0)
		{
			printf("%d\n", (b - a) / 3 + 1);
		}
		else
		{
			c = b - a;
			if (c % 3 == 0)
			{
				printf("%d\n", c / 3);
			}
			else
			{
				if ((a % 3 + c % 3) >= 3)
				{
					printf("%d\n", c / 3 + 1);
				}
				else
				{
					printf("%d\n", c / 3);
				}
			}
		}
	}
	return 0;
}
