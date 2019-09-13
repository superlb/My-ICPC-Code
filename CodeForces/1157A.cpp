#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,sum=9;
	cin >> n;
	while (n >= 10)
	{
		sum += 10 - n % 10;
		n += 10 - n % 10;
		while (n % 10 == 0)
		{
			n /= 10;
		}
	}
	cout << sum;
	return 0;
}
