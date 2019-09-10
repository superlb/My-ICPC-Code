#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define lowbit(x) (x&-x)
long long n;
long long sum[500001];
void update(long long k, long long x)
{
	for (long long i = k; i <= n; i += lowbit(i))
		sum[i] += x;
}
long long getsum(long long x)
{
	long long ans = 0;
	for (long long i = x; i; i -= lowbit(i))
		ans += sum[i];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	memset(sum, 0, sizeof(sum));
	int m;
	int a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		update(i, a);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(b,c);
		}
		else if (a == 2)
		{
			cout << getsum(c) - getsum(b - 1)<<endl;
		}
	}
	return 0;
}
