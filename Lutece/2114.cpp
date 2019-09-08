#include <cstdio>
#include <stack>
#define N 1000
using namespace std;
int main()
{
	int i, n, target[N];
	while (scanf("%d", &n) == 1)
	{
		stack<int> s;
		for (i = 0; i < n; i++)
		{
			scanf("%d",&target[i]);
		}
		int A = 1, B = 0, ok = 1;
		while (B < n)
		{
			if (A == target[B])
			{
				A++; B++;
			}
			else if (!s.empty() && s.top()==target[B])
			{
				s.pop(); B++;
			}
			else if (A <= n)
			{
				s.push(A++);
			}
			else
			{
				ok = 0; break;
			}
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}
