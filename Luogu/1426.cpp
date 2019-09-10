#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	double s, x, sum = 0,q=7.0;
	cin >> s >> x;
	while (sum<s-x)
	{
		sum += q;
		q *= 0.98;
	}
	sum += q;
	if (sum > s + x)
	{
		cout << "n";
	}
	else
	{
		cout << "y";
	}
	return 0;
}
