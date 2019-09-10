#include <bits/stdc++.h>
using namespace std;
int n, k, sum[10001] = { 0 }, f[10001] = { 0 },num=1;
struct task
{
	int s, e;
}tasklist[10001];
bool cmp(task a, task b)
{
	return a.s > b.s;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> tasklist[i].s >> tasklist[i].e;
		++sum[tasklist[i].s];
	}
	sort(tasklist + 1, tasklist + 1 + k, cmp);
	for (int i = n; i >= 1; --i)
	{
		if (sum[i] == 0)
		{
			f[i] = f[i + 1] + 1;
		}
		else
		{
			for (int j = 1; j <= sum[i]; ++j)
			{
				if (f[i + tasklist[num].e] > f[i])
					f[i] = f[i + tasklist[num].e];
				++num;
			}
		}
	}
	cout << f[1] << endl;
	//system("pause");
	return 0;
}
