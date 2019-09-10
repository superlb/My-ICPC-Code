#include <bits/stdc++.h>
using namespace std;
long long b[500001];
long long n;
#define lowbit(x) (x&-x)
void update(long long k, long long x)
{
	for (long long i = k; i <= n; i += lowbit(i))
	{
		b[i] += x;
	}
}
long long getsum(long long x)
{
	long long ans = 0;
	for (long long i = x; i; i -= lowbit(i))
		ans += b[i];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	long long m, a, last,x,y,k;
	cin >> n >> m;
	last = 0;
	memset(b, 0, sizeof(b));
	for (long long i = 1; i <= n; i++)
	{
		cin >> a;
		update(i, a - last);
		last = a;
	}
	for (long long i = 0; i < m; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> x >> y >> k;
			update(x, k);
			update(y+1, -k);
		}
		else if (a == 2)
		{
			cin >> x;
			cout << getsum(x) << endl;
		}
	}
	return 0;
}
