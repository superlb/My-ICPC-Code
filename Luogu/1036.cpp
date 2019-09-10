#include <iostream>
using namespace std;
long num[20];
int sum = 0;
int n, k;
bool isprime(long pri)
{
	for (int j = 2; j < pri; ++j)
	{
		if (pri%j == 0)return false;
	}
	++sum;
	return true;
}
void solve(int k1, long sum1, int n1)
{
		--k1;
		sum1 += num[n1];
		if (k1)
		{
			for (int i1 = n1 + 1; i1 < n; ++i1)
			{
				solve(k1,sum1,i1);
			}
		}
		else
		{
			isprime(sum1);
		}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	for (int s = 0; s < n; ++s)
	{
		solve(k, 0, s);
	}
	cout << sum;
	return 0;
}
