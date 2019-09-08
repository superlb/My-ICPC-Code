#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
int parent[MAXN];
int sum[MAXN];
int find(int x)
{
	if (x != parent[x])
	{
		int linshi = parent[x];
		parent[x] = find(parent[x]);
		sum[x] += sum[linshi];
		sum[x] = sum[x] % 2;
	}
	return parent[x];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m,pos=0,w;
	memset(sum, 0, sizeof(sum));
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
	}
	int l, r;
	string str;
	for (int i = 1; i <= m; ++i)
	{
		cin >> l >> r >> str;
		--l;
		if (!pos)
		{
			if (str[0] == 'e')
			{
				w = 0;
			}
			else
			{
				w = 1;
			}
			int p1 = find(l), p2 = find(r);
			if (p1 != p2)
			{
				parent[p1] = p2;
				sum[p1] = (w + sum[r] - sum[l] + 2) % 2;
			}
			else
			{
				if (w != (sum[r] - sum[l] + 2) % 2)
				{
					pos = i;
				}
			}
		}
	}
	if (pos)
	{
		cout << pos-1;
	}
	else
	{
		cout << "ORZQHQH";
	}
	return 0;
}
