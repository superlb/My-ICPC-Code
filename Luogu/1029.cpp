#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int gcd(int x, int y)
{
	if (y == 0) { return x; }
	return gcd(y, x%y);
}
int main()
{
	int x, y, q,w, sum = 0;
	cin >> x >> y;
	q = y * x;
	w = sqrt(q);
	for (int i = 1; i <= w; i++)
	{
		if (q % i == 0 && gcd(i, q / i) == x)
			++sum;
	}
	cout << sum*2;
	return 0;
}
