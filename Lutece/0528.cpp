#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000001
int num[N];
using namespace std;
int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		memset(num, 0, N * sizeof(int));
		int k;
		for(int i=0;i<n;++i)
		{
			cin >> k;
			++num[k + 500000];
		}
		for (int i = 0; i < 1000001;)
		{
			if (num[1000000 - i] > 0)
			{
				--num[1000000 - i];
				cout << 500000 - i << " ";
				if (num[1000000 - i] == 0)++i;
				--m;
				if (m == 0)break;
			}
			else
				++i;
		}
		printf("\n");
	}
	return 0;
}
