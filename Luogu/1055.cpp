#include <stdio.h>
int main()
{
	int num[9];
	int sum=0;
	char x;
	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",&num[0], &num[1], & num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &x);
	for (int i = 0; i < 9; i++)
	{
		sum += num[i] * (i + 1);
	}
	if (x == 'X')
	{
		if (sum % 11 == 10)
		{
			printf("Right");
		}
		else
		{
			printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1d", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], sum % 11);
		}
	}
	else
	{
		if (sum % 11 == x-'0' )
		{
			printf("Right");
		}
		else
		{
			if (sum % 11 == 10)
			{
				printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-X", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8]);
			}
			else
			{
				printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1d", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], sum % 11);
			}
		}
	}
	return 0;
}
