#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a, b, c,d;
	cin >> a >> b;
	c = abs(a - b);
	d = min(a, b);
	if (c == 0)
	{
		cout << 0;
	}
	else if (a == 1 || b == 1)
	{
		cout << 0;
	}
	else if (c < d)
	{
		if (d%c == 0)
		{
			cout << 0;
		}
		else
		{
			cout << c - d % c;
		}
	}
	else if (c == d || max(a,b)%min(a,b)==0)
	{
		cout << 0;
	}
	else
	{
		int e = sqrt(c);
		int last=-1;
		for (int i = 1; i <= e; ++i)
		{
			if (c%i==0)
			{
				if (i > d)
				{
					d = i;
					last = -1;
					break;
				}
				if (c / i <= d)
				{
					d = last;
					break;
				}
				else
				{
					last = c / i;
				}
			}
		}
		if (last != -1)
		{
			d = last;
		}
		if (d == min(a, b))
		{
			cout << c-d;
		}
		else
		{
			cout << d - min(a, b);
		}
	}
	return 0;
}
