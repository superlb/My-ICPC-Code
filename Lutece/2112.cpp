#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long sum[20], max = -1;
	long long n;
	cin >> n;
	for (long long i = 0; i < n; i++)
	{
		cin >> sum[i];
	}
	for (long long i = 0; i < n; ++i)
	{
		long long num = sum[i];
		if (num > max)max = num;
		for (long long j = i + 1; j < n; j++)
		{
			num *= sum[j];
			if (num > max)max = num;
		}
	}
	cout << max;
	return 0;
}
