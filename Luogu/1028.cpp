#include <iostream>
using namespace std;
int num[1000];
int solve(int a)
{
	int sum1 = 0;
	if (a == 1)
	{
		return 0;
	}
	else
	{
		if (num[a] == 0)
		{
			sum1 += a / 2;
			for (int i = 1; i <= a / 2; ++i)
			{
				sum1 += solve(i);
			}
			num[a] = sum1;
		}
		else
		{
			sum1 = num[a];
		}
	}
	return sum1;
}
int main()
{
	int n;
	cin >> n;
	cout << solve(n) + 1;
	return 0;
}
