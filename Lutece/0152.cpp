#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int sum1=0, sum2 = 0;
	int a, b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		sum2 += a;
		b = b / 10;
		switch (b)
		{
		case 10:
		case 9:sum1 += 4 * a; break;
		case 8:sum1 += 3 * a; break;
		case 7:sum1 += 2 * a; break;
		case 6:sum1 += 1 * a; break;
		default:break;
		}
	}
	printf("%.2f", (float)sum1 / sum2);
	return 0;
}
