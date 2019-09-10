#include<bits/stdc++.h>
using namespace std;
int extgcd(int a, int b, int& x, int& y)
{
	int d = a;
	if (b != 0)
	{
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1; y = 0;
	}
	return d;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int a1, b1, x1, y1;
	cin >> a1 >> b1;
	extgcd(a1,b1,x1,y1);
	cout << ((x1 < 0) ? (x1 + b1) : x1);
	//system("pause");
	return 0;
}
