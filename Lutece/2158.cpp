#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int v[MAXN];
int lsh_v[MAXN];
int ans[MAXN];
int sum[MAXN];
int cnt[MAXN];
int n, m, l, r, len, nowl = 1, nowr = 0, lsh_len, res=0, x;
struct query
{
	int L, R, ID,block;
	query() {}
	query(int _L, int _R, int _ID)
	{
		L = _L; R = _R; ID = _ID;
		block = l / len;
	}
	bool operator < (const query &a) const
	{
		if (block == a. block)
		{
			return R < a.R;
		}
		return block < a.block;
	}
}q[MAXN];
void add(int pos)
{
	x = v[pos];
	if(sum[cnt[x]]>0)sum[cnt[x]]--;
	sum[++cnt[x]]++;
	res = max(res, cnt[x]);
}
void erase(int pos)
{
	x = v[pos];
	if (sum[cnt[x]] > 0)sum[cnt[x]]--;
	if (res == cnt[x])
	{
		if (sum[cnt[x]] == 0)
		{
			res--;
		}
	}
	if (cnt[x] > 0)
	{
		sum[--cnt[x]]++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	memset(sum, 0, sizeof(sum));
	memset(cnt, 0, sizeof(cnt));
	cin >> n >> m;
	len = sqrt(n);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		lsh_v[i] = v[i];
	}
	sort(lsh_v + 1, lsh_v + 1 + n);
	lsh_len = unique(lsh_v + 1, lsh_v + 1 + n) - lsh_v - 1;
	for (int i = 1; i <= n; ++i)
	{
		v[i] = lower_bound(lsh_v + 1, lsh_v + 1 + lsh_len,v[i]) - lsh_v;
	}
	for (int i = 1; i <= m; ++i)
	{
		cin >> l >> r;
		q[i] = query(l,r,i);
	}
	sort(q+1,q+m+1);
	for (int i = 1; i <= m; ++i)
	{
		while (nowr < q[i].R)add(++nowr);
		while (nowl > q[i].L)add(--nowl);
		while (nowr > q[i].R)erase(nowr--);
		while (nowl < q[i].L)erase(nowl++);
		ans[q[i].ID] = res;
	}
	for (int i = 1; i <= m; ++i)
	{
		cout << ans[i] << endl;
	}
	//system("pause");
	return 0;
}
