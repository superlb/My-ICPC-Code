#include <cstdio>
int main()
{
	int t;
	int a, b, c;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n", a + b + c);
	}
	return 0;
}
