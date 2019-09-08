#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000002
long long bit1[MAXN], bit2[MAXN], n;
inline long long lowbit(long long x)
{
	return x & -x;
}
void add(long long x, long long val)
{
	for (long long i = x; i > 0; i -= lowbit(i))
		bit1[i] += val;
	for (long long i = x; i <= n; i += lowbit(i))
		bit2[i] += x * val;
}
long long sum(long long x) {
	if (!x)
		return 0;
	long long ret1 = 0, ret2 = 0;
	for (long long i = x; i <= n; i += lowbit(i))
		ret1 += bit1[i];
	for (long long i = x - 1; i > 0; i -= lowbit(i))
		ret2 += bit2[i];
	return ret1 * x + ret2;
}
int main()
{
	ios::sync_with_stdio(false);
	long long m;
	long long a, b, c, d;
	memset(bit1, 0, sizeof(bit1));
	memset(bit2, 0, sizeof(bit2));
	cin >> n >> m;
	n++;
	for (long long i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d;
		if (a == 0)
		{
			add(c, d);
			if (b > 1)
				add(b - 1, -d);
		}
		else
		{
			cout << sum(c) - sum(b - 1)<<endl;
		}
	}
	return 0;
}
