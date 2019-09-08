#include <cstdio>
int main()
{
	int h,m;
	int x1[25] = {00,10,20,30,40,50,-1,-1,-1,-1,01,11,21,31,41,51,-1,-1,-1,-1,02,12,22,32,00};
	scanf("%d:%d", &h, &m);
	int k = h;
	int sum = 0;
	while (x1[k] == -1)
	{
		++k;
	}
	if (x1[k] >= m)
	{
		sum = (k - h) * 60 + (x1[k] - m);
	}
	else
	{
		while (x1[k + 1] == -1)
		{
			++k;
		}
		if (x1[h]==-1)
		{
			sum = (k - h-1) * 60 + (60 - m + x1[k]);
		}
		else
		{
			sum = (k - h) * 60 + (60 - m + x1[k + 1]);
		}
	}
	printf("%d", sum);
	return 0;
}
