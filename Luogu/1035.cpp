#include<iostream>

using namespace std;
int main()
{
	long double k,sum(0);
	long n(1);
	const double one(1);
	cin >> k;
	while (k >= sum)
	{
		sum += one / n;
		n++;
	}
	cout << (--n);
	return 0;
}
