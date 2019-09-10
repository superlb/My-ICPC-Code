#include <iostream>
using namespace std;
int prime[2500];
int w = 1;
bool isprime(int pri)
{
	for (int i = 0; i < w; ++i)
	{
		if (pri%prime[i] == 0)return false;
	}
	prime[w] = pri;
	++w;
	return true;
}
int main()
{
	int n;
	int num[3];
	prime[0] = 2;
	bool min = true;
	for (int i = 3; i < 20000; i+=2)
	{
		isprime(i);
	}
	cin >> n;
	for (int d1 = 0; d1 < w && min; ++d1)
	{
		for (int d2 = 0; d2 < w && min; ++d2)
		{
			for (int d3 = 0; d3 < w && min; ++d3)
			{
				if (prime[d1] + prime[d2] + prime[d3] == n)
				{
					min = false;
					num[0] = prime[d1];
					num[1] = prime[d2];
					num[2] = prime[d3];
				}
			}
		}
	}
	cout << num[0] << " " << num[1] << " " << num[2];
	return 0;
}
