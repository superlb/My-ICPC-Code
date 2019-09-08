#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, x;
	int num[100000];
	int sum = 0,x1;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	x1 = num[x - 1];
	for (int i = 0; i < n; i++)
	{
		if (num[i] >= x1)sum += num[i] - x1 + 1;
	}
	sum--;
	printf("%d", sum);
	return 0;
}
