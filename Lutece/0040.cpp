#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
	int n,a,sum;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)break;
		sum = 0;
		priority_queue<int, vector<int>, greater<int> > pque;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			pque.push(a);
		}
		for (int i = 0; i < n / 2 + 1; i++)
		{
			sum += pque.top() / 2 + 1;
			pque.pop();
		}
		printf("%d\n", sum);

	}
	return 0;
}
