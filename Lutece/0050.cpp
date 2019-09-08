#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t,n;
	int a[100000];
	int b[100000];
	double max1=1000000000, min1=0;
	double sum = 0;
	bool is;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		is = true;
		sum = 0;
		max1 = 1000000000;
		min1 = 0;
		cin >> n;
		for (int d1 = 0; d1 < n; ++d1)
		{
			cin >> a[d1];
		}
		sum = a[0];
		for (int d2 = 0; d2 < n-1; ++d2)
		{
			cin >> b[d2];
			sum += b[d2];
			if (sum / (d2 + 1) > min1)
				min1 = sum / (d2 + 1);
			sum += a[d2 + 1];
			if (sum / (d2 + 1) < max1)
				max1 = sum / (d2 + 1);
			if (min1 > max1)is = false;
		}
		if (is)
			printf("%.2f\n", min1);
		else
			printf("impossible\n");
	}
	return 0;
}
