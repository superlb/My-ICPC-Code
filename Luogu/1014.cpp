#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,k=1,sum;
	cin >> n;
	sum = n;
	while (k*(k + 1) / 2 < n)
	{
		++k;
	}
	--k;
	if (k % 2)
	{
		sum -= k * (k + 1) / 2;
		cout << sum << "/" << (k + 2 - sum);
	}
	else
	{
		sum -= k * (k + 1) / 2;
		cout << (k + 2 - sum) << "/" << sum;
	}
	return 0;
}
