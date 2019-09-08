#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000001
long long add[MAXN << 2], st[MAXN << 2], maxnum[MAXN << 2], minnum[MAXN << 2];
void build(long long o, long long l, long long r)
{
	if (l == r)st[o] = 0;
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
	maxnum[o] = max(maxnum[o << 1], maxnum[o << 1 | 1]);
	minnum[o] = min(minnum[o << 1], minnum[o << 1 | 1]);
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
		maxnum[o << 1] += add[o];
		maxnum[o << 1 | 1] += add[o];
		minnum[o << 1] += add[o];
		minnum[o << 1 | 1] += add[o];
		add[o] = 0;
	}
}

void update(long long o, long long l, long long r, long long ql, long long qr, long long addv)
{
	if (ql <= l && qr >= r)
	{
		add[o] += addv;
		st[o] += addv * (r - l + 1);
		maxnum[o] += addv;
		minnum[o] += addv;
		return;
	}

	pushdown(o, l, r);
	long long m = l + ((r - l) >> 1);
	if (ql <= m)update(o << 1, l, m, ql, qr, addv);
	if (qr >= m + 1)update(o << 1 | 1, m + 1, r, ql, qr, addv);
	pushup(o);
}
struct returnvalue
{
	long long ans, maxs, mins;
	returnvalue operator=(const returnvalue& a)
	{
		this->ans = a.ans;
		this->maxs = a.maxs;
		this->mins = a.mins;
		return *this;
	}
};
returnvalue query(long long o, long long l, long long r, long long ql, long long qr)
{
	returnvalue qwe;
	qwe.ans = 0;
	qwe.maxs = -999999999999;
	qwe.mins = 999999999999;
	if (ql <= l && qr >= r)
	{
		qwe.ans = st[o];
		qwe.maxs = maxnum[o];
		qwe.mins = minnum[o];
		return qwe;
	}
	pushdown(o, l, r);
	long long m = l + ((r - l) >> 1);
	if (ql <= m)
	{
		returnvalue asd = query(o << 1, l, m, ql, qr);
		qwe.ans += asd.ans;
		qwe.maxs = max(asd.maxs, qwe.maxs);
		qwe.mins = min(asd.mins, qwe.mins);
	}
	if (qr >= m + 1)
	{
		returnvalue asd = query(o << 1 | 1, m + 1, r, ql, qr);
		qwe.ans += asd.ans;
		qwe.maxs = max(asd.maxs, qwe.maxs);
		qwe.mins = min(asd.mins, qwe.mins);
	}
	return qwe;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long n, q,o,a,s,d;
	returnvalue poi;
	cin >> n >> q;
	build(1,1,n);
	for (long long i = 0; i < q; ++i)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> a >> s >> d;
			update(1,1,n,a,s,d);
		}
		else if (o == 2)
		{
			cin >> a >> s;
			poi=query(1,1,n,a,s);
			cout << poi.ans << endl;
		}
		else if (o == 3)
		{
			cin >> a >> s;
			poi = query(1, 1, n, a, s);
			cout << poi.maxs-poi.mins << endl;
		}
	}
	return 0;
}
