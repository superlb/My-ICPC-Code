#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 100001;
long long a[MAXN],minnum[MAXN<<2];
void build(long long o, long long l, long long r)
{
	if (l == r)minnum[o] = a[l];
	else
	{
		long long m = l + ((r - l) >> 1);
		build(o << 1, l, m);
		build((o << 1) | 1, m + 1, r);
		minnum[o] = min(minnum[o<<1],minnum[(o<<1)|1]);
	}
}
long long query(long long o, long long l, long long r, long long ql, long long qr)
{
	long long nowmin = 1000000000000000ll;
	if (ql <= l && qr >= r)
	{
		return minnum[o];
	}
	long long m = l + ((r - l) >> 1);
	if (ql <= m)
	{
		nowmin = min(nowmin, query(o << 1, l, m, ql, qr));
	}
	if (qr >= m + 1)
	{
		nowmin = min(nowmin, query(o << 1 | 1, m + 1, r, ql, qr));
	}
	return nowmin;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long n, m,linshi;
	cin >> n >> m;
	a[0] = 0;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> linshi;
		a[i] = a[i - 1] + linshi;
	}
	build(1,1,n);
	long long maxnum = a[1];
	for (long long i = 2; i <= n; ++i)
	{
		if (i > m)
		{
			linshi = a[i] - query(1, 1, n,i - m, i - 1);
			if (linshi > maxnum)
			{
				maxnum = linshi;
			}
		}
		else
		{
			linshi = a[i] - min(query(1, 1, n, 1, i - 1),0ll);
			if (linshi > maxnum)
			{
				maxnum = linshi;
			}
		}
	}
	cout << maxnum;
	//system("pause");
	return 0;
}
