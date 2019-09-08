#include <iostream>
using namespace std;
bool is_prime(int a)
{
	if (a == 1)return false;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)return false;
	}
	return true;
}
int main()
{
	int sum = 0, n,x,n2;
	cin >> n;
	n2 = n;
	while (n--)
	{
		cin >> x;
		if (is_prime(x))++sum;
	}
	cout << sum << " " << n2;
	return 0;
}
