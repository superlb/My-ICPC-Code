#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long a, b, c, d;
	long long n,s,sum=0;
	long long squ[1001];
	vector<long long> v;
	vector<long long>::iterator it1, it2;
	cin >> a >> b >> c >> d;
	for (long long i = 0; i < 1001; ++i)
	{
		squ[i] = i * i;
	}
	for (long long d1 = 1; d1 <= 1000; ++d1)
	{
		for (long long d2 = 1; d2 <= 1000; ++d2)
		{
			v.push_back(-(c*squ[d1]+d*squ[d2]));
		}
	}
	it1 = v.begin();
	it2 = v.end();
	stable_sort(it1,it2);
	for (long long d1 = 1; d1 <= 1000; ++d1)
	{
		for (long long d2 = 1; d2 <= 1000; ++d2)
		{
			n = a * squ[d1] + b * squ[d2];
			auto qwe=equal_range(it1,it2,n);
			s = qwe.second - qwe.first;
			if (s)
			{
				sum += s * 16;
			}
		}
	}
	cout << sum;
	return 0;
}
