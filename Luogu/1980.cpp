#include<iostream>

using namespace std;
int main()
{
	long n1;
	int x;
	long k;
	long sum(0);
	cin >> n1 >> x;
	for (long n2 = 1;n1 >= n2;++n2)
	{
		k = n2;
		do
		{
			if ((k % 10) == x)
			{
				++sum;
			}
			if (k < 10)break;
			k /= 10;
			if (k == x)++sum;
		} while (k >= 10);
	}
	cout << sum;
	return 0;
}
