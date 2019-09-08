#include<bits/stdc++.h>
using namespace std;
const long long MAXN = 100001ll;
const long long MODNUM = 1000000007ll;
long long a[MAXN];
struct node
{
	long long l, r, sum, squsum, mul, add;
	node *left, *right;
	node()
	{
		sum = 0ll; squsum = 0ll; mul = 1ll; add = 0ll;
		left = NULL; right = NULL;
	}
};
node *root = new node();
void build(node *aroot, long long l, long long r)
{
	aroot->l = l;
	aroot->r = r;
	if (l == r)
	{
		aroot->sum = a[l];
		aroot->squsum = a[l] * a[l] % MODNUM;
	}
	else
	{
		aroot->left = new node();
		aroot->right = new node();
		build(aroot->left, l, (l + r) >> 1ll);
		build(aroot->right, ((l + r) >> 1ll) + 1ll, r);
		aroot->sum = (aroot->left->sum + aroot->right->sum) % MODNUM;
		aroot->squsum = (aroot->left->squsum + aroot->right->squsum) % MODNUM;
	}
}
void pushup(node *aroot)
{
	if (aroot->left != NULL && aroot->right != NULL)
	{
		aroot->sum = (aroot->left->sum + aroot->right->sum) % MODNUM;
		aroot->squsum = (aroot->left->squsum + aroot->right->squsum) % MODNUM;
	}
}
void refresh(node *aroot, long long mulv, long long addv)
{
	aroot->squsum = (aroot->squsum * mulv% MODNUM) * mulv% MODNUM;
	aroot->sum = aroot->sum * mulv% MODNUM;
	aroot->squsum = (aroot->squsum% MODNUM + addv * aroot->sum% MODNUM + addv * aroot->sum% MODNUM + ((aroot->r - aroot->l + 1ll) * addv % MODNUM) * addv% MODNUM) % MODNUM;
	aroot->sum = (aroot->sum % MODNUM + addv * (aroot->r - aroot->l + 1ll) % MODNUM) % MODNUM;
	aroot->mul = (aroot->mul * mulv) % MODNUM;
	aroot->add = (aroot->add * mulv% MODNUM + addv) % MODNUM;
}
void pushdown(node *aroot)
{
	if (aroot->add != 0ll || aroot->mul != 1ll)
	{
		if (aroot->left != NULL && aroot->right != NULL)
		{
			refresh(aroot->left, aroot->mul, aroot->add);
			refresh(aroot->right, aroot->mul, aroot->add);
		}
		aroot->add = 0ll; aroot->mul = 1ll;
	}
}
void update(node *aroot, long long l, long long r, long long mulv, long long addv)
{
	if (aroot == NULL)
	{
		return;
	}
	if (l == aroot->l && aroot->r == r)
	{
		refresh(aroot, mulv, addv);
		return;
	}
	pushdown(aroot);
	long long m = (aroot->l + aroot->r) >> 1ll;
	if (r <= m)
	{
		update(aroot->left, l, r, mulv, addv);
	}
	else if (l > m)
	{
		update(aroot->right, l, r, mulv, addv);
	}
	else
	{
		update(aroot->left, l, m, mulv, addv);
		update(aroot->right, m + 1ll, r, mulv, addv);
	}
	pushup(aroot);
}
struct returnvalue
{
	long long ans, squans;
	returnvalue()
	{
		ans = 0ll; squans = 0ll;
	}
};
returnvalue query(node *aroot, long long l, long long r)
{
	returnvalue linshi;
	if (aroot == NULL)
	{
		return linshi;
	}
	if (l == aroot->l && aroot->r == r)
	{
		linshi.ans = aroot->sum;
		linshi.squans = aroot->squsum;
		return linshi;
	}
	pushdown(aroot);
	long long m = (aroot->l + aroot->r) >> 1ll;
	if (r <= m)
	{
		return query(aroot->left, l, r);
	}
	else if (l > m)
	{
		return query(aroot->right, l, r);
	}
	else
	{
		returnvalue asd;
		asd = query(aroot->left, l, m);
		linshi.ans = (linshi.ans + asd.ans) % MODNUM;
		linshi.squans = (linshi.squans + asd.squans) % MODNUM;
		asd = query(aroot->right, m + 1ll, r);
		linshi.ans = (linshi.ans + asd.ans) % MODNUM;
		linshi.squans = (linshi.squans + asd.squans) % MODNUM;
		return linshi;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long n, q, o, L, R, K;
	cin >> n >> q;
	for (long long i = 1ll; i <= n; ++i)
	{
		cin >> a[i];
	}
	build(root, 1ll, n);
	for (long long i = 1ll; i <= q; ++i)
	{
		cin >> o;
		if (o == 1ll)
		{
			cin >> L >> R >> K;
			update(root, L, R, 1, K);
		}
		else if (o == 2ll)
		{
			cin >> L >> R >> K;
			update(root, L, R, K, 0);
		}
		else if (o == 3ll)
		{
			cin >> L >> R >> K;
			update(root, L, R, 0, K);
		}
		else if (o == 4ll)
		{
			cin >> L >> R;
			returnvalue qwe = query(root, L, R);
			long long poi = qwe.squans*(R - L + 1ll) % MODNUM - qwe.ans*qwe.ans % MODNUM;
			cout << ((poi < 0ll) ? (poi + MODNUM) : poi) << endl;
		}
	}
	return 0;
}
