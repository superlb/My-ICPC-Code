#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int k, x, y,a=1;
	cin >> k;
	while (1)
	{
		x = k + a;
		++a;
		y = k * x / (x - k);
		if (x > y)break;
		if ((k*x)%y == 0)
		{
			cout << "1/" << k << "=1/" << x << "+1/" << y << endl;
		}
	}
	cin >> k;
	return 0;
}
