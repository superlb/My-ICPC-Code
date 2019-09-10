#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
int pri[10000000];
using namespace std;
bool isprime(int x)
{
	if (x == 1)return false;
	if (pri[x])
	{
		return pri[x] == 1 ? true : false;
	}
	int q = sqrt(x);
	for (int i = 2; i <= q; i++)
	{
		if (x%i == 0)
		{
			pri[x] = -1;
			return false;
		}
	}
	pri[x] = 1;
	return true;
}
int main()
{
	memset(pri, 0, sizeof(pri));
	int n, m,z;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d",&z);
		printf(isprime(z) ? "Yes\n" : "No\n");
	}
	return 0;
}
