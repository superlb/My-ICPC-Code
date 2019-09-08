#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l, r;
	bool operator < (const node &a) const
	{
		if (l <= a.r && a.r <= r)
			return false;
		if (l <= a.l && a.l <= r)
			return false;
		if (a.l <= l && l <= a.r)
			return false;
		if (a.l <= r && r <= a.r)
			return false;
		return r < a.r;
	}
};
set<node> s;
node merge(node a, node b)
{
	node qwe;
	qwe.l = min(a.l, b.l);
	qwe.r = max(a.r, b.r);
	return qwe;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,q,w;
	node linshi;
	set<node>::iterator it;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> q >> w;
		linshi.l = q; linshi.r = w;
		it=s.find(linshi);
		while (it != s.end())
		{
			linshi = merge(linshi, *it);
			s.erase(it);
			it = s.find(linshi);
		}
		s.insert(linshi);
		cout << s.size() << " ";
	}
	return 0;
}
