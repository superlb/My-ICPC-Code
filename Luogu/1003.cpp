#include <cstdio>
using namespace std;
struct num
{
	int a, b, g, k;
}nums[10001];
int main()
{
	int n,x,y,sum=-1;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &nums[i].a, &nums[i].b, &nums[i].g,&nums[i].k);
	}
	scanf("%d%d", &x,&y);
	for (int i = 1; i <= n; i++)
	{
		if (x >= nums[i].a && x <= nums[i].a + nums[i].g)
			if (y >= nums[i].b && y <= nums[i].b + nums[i].k)
				sum = i;
	}
	printf("%d",sum);
	return 0;
}
