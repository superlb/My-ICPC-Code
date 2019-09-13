#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long d1, d2, d3, d4,sum;
	cin >> d1 >> d2 >> d3 >> d4;
	sum = (d1 + d2 + d3 + d4)/3;
	if (sum - d1 != 0)
	{
		cout << sum - d1 << " ";
	}
	if (sum - d2 != 0)
	{
		cout << sum - d2 << " ";
	}
	if (sum - d3 != 0)
	{
		cout << sum - d3 << " ";
	}
	if (sum - d4 != 0)
	{
		cout << sum - d4 << " ";
	}
	return 0;
}
