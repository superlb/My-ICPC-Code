#include<iostream>
using namespace std;
int main()
{
	int a, b,d,f;
	int e, g;
	double c=0;
	cin >> a;
	if (a >= 150)
	{
		c += 150 * 0.4463;
		if (a >= 400)
		{
			c += 250 * 0.4663;
			b = a - 400;
			c += b*0.5663;
			d = c * 10;
			e = c * 100;
			c = d / 10;
			f = d - c * 10;
			c += f*0.1;
			g = e - (e / 10) * 10;
			if (g >= 5) { c += 0.1; }
			cout << c;
			return 0;
		}
		b = a - 150;
		c += b*0.4663;
		d = c * 10;
		e = c * 100;
		c = d / 10;
		f = d - c * 10;
		c += f*0.1;
		g = e - (e / 10) * 10;
		if (g >= 5) { c += 0.1; }
		cout << c;
		return 0;
	}
	c += a*0.4463;
	d = c * 10;
	e = c * 100;
	c = d / 10;
	f = d - c * 10;
	c += f*0.1;
	g = e - (e / 10) * 10;
	if (g >= 5) { c += 0.1; }
	cout << c;
	return 0;
}
