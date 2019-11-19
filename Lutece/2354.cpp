#include <iostream>
using namespace std;
long long solve(long long a)
{
	if (a % 2 == 0)return 2;
	if (a % 3 == 0)return 3;
	if (a % 5 == 0)return 5;
	if (a % 7 == 0)return 7;
	for (long long i = 11; i < a / 11; i += 2)
	{
		if (a%i == 0)return i;
	}
	return a;
}
int main()
{
	long long n;
	long long sma;
	long long sum = 0;
	cin >> n;
	sma = solve(n);
	while (sma != 2 && n!=0)
	{
		n -= sma;
		sma = solve(n);
		++sum;
	}
	sum += n / 2;
	cout << sum;
	return 0;
}
