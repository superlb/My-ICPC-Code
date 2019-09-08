#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long sum[30];
	sum[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		sum[i] = (sum[i + 1] + 1) * 3;

	}
	for (int i = 0; i<n; i++)
	{
		cout << sum[i]<<" ";
	}
	return 0;
}
