#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a, b, c,d;
	int q;
	cin >> a >> b >> c;
	if (a > b)
	{
		d = a; a = b; b = d;
	}
	if (c > b)
	{
		d = c; c = b; b = d;
	}
	q = abs(abs(a - b)- abs(b - c));
	if (q % 2)
	{
		cout << (q+3) / 2+ min(abs(a - b),abs(b - c));
	}
	else
	{
		cout << q / 2 + min(abs(a - b), abs(b - c));
	}
	return 0;
}
