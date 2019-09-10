#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 100001;
long long add[MAXN << 2], st[MAXN << 2],a[MAXN];
void build(long long o, long long l, long long r)
{
	if (l == r)st[o] = a[l];
	else
	{
		long long m = l + ((r - l) >> 1);
		build(o << 1, l, m);
		build((o << 1) | 1, m + 1, r);
		st[o] = st[o << 1] + st[(o << 1) | 1];
	}
}
void pushup(long long o)
{
	st[o] = st[o << 1] + st[o << 1 | 1];
}
void pushdown(long long o, long long l, long long r)
{
	if (add[o])
	{
		add[o << 1] += add[o];
		add[o << 1 | 1] += add[o];
		long long m = l + ((r - l) >> 1);
		st[o << 1] += add[o] * (m - l + 1);
		st[o << 1 | 1] += add[o] * (r - m);
		add[o] = 0;
	}
}

void update(long long o, long long l, long long r, long long ql, long long qr, long long addv)
{
	if (ql <= l && qr >= r)
	{
		add[o] += addv;
		st[o] += addv * (r - l + 1);
		return;
	}
	pushdown(o, l, r);
	long long m = l + ((r - l) >> 1);
	if (ql <= m)update(o << 1, l, m, ql, qr, addv);
	if (qr >= m + 1)update(o << 1 | 1, m + 1, r, ql, qr, addv);
	pushup(o);
}
long long query(long long o, long long l, long long r, long long ql, long long qr)
{
	long long ans = 0;
	if (ql <= l && qr >= r)
	{
		return st[o];
	}
	pushdown(o, l, r);
	long long m = l + ((r - l) >> 1);
	if (ql <= m)
	{
		ans += query(o << 1, l, m, ql, qr);
	}
	if (qr >= m + 1)
	{
		ans += query(o << 1 | 1, m + 1, r, ql, qr);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	build(1,1,n);
	long long x, y, k,q;
	for (long long i = 1; i <= m; i++)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> x >> y >> k;
			update(1,1,n,x,y,k);
		}
		else if (q == 2)
		{
			cin >> x >> y;
			cout << query(1,1,n,x,y) << endl;
		}
	}
	return 0;
}
