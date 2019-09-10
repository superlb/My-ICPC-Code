#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[100001] = {0};
	a[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k && i - j >= 0; ++j)
		{
			a[i] += a[i - j];
			a[i] %= 100003;
		}
	}
	cout << a[n];
	//system("pause");
	return 0;
}
