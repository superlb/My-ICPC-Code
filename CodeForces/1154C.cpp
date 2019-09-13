#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a, b, c, sum = 0,max1=0;
	int s[21] = {1,2,3,1,3,2,1,1,2,3,1,3,2,1,1,2,3,1,3,2,1};
	cin >> a >> b >> c;
	int q = min(min(a/3,b/2),c/2);
	sum += q * 7;
	a -= q * 3; b -= q * 2; c -= q * 2;
	for (int i = 0; i < 8; i++)
	{
		int a1 = a, b1 = b, c1 = c,d=0;
		while (true)
		{
			if (s[i + d] == 1)
			{
				if (a1)
					a1--;
				else
					break;
			}
			else if (s[i + d] == 2)
			{
				if (b1)
					b1--;
				else
					break;
			}
			else if (s[i + d] == 3)
			{
				if (c1)
					c1--;
				else
					break;
			}
			d++;
		}
		if (d >max1)
			max1 = d;
	}
	cout << sum + max1;
	return 0;
}
