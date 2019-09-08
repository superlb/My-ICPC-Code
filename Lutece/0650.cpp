#include <iostream>
using namespace std;
int main()
{
	int t;
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int y, m, d;
	int sum;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		sum = 0;
		cin >> y >> m >> d;
		for (int j = 1; j < m; j++)
		{
			if (j == 2 && y % 4 == 0)
			{
				if (y % 100 == 0 && y % 400 != 0)
				{
					sum += 28;
				}
				else
				{
					sum += 29;
				}
			}
			else
			{
				sum += a[j-1];
			}
		}
		sum += d;
		cout << sum << endl;
	}
	return 0;
}
