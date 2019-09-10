#include<iostream>

using namespace std;
int main()
{
	int x;
	long int k;
	long long sum(0);
	cin >> x;
	cin >> k;
	for (int n = 1;n <= k;++n)
	{
		if (x == 6)
		{
			++x;
			continue;
		}
		else if (x == 7)
		{
			x = 1;
			continue;
		}
		sum += 250;
		++x;
	}
	cout << sum;
	return 0;
}
