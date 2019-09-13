#include<bits/stdc++.h>
using namespace std;
int s[200000];
int main()
{
	ios::sync_with_stdio(false);
	int n, a, b,sum=0,maxa;
	cin >> n >> b >> a;
	maxa = a;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i <= n; i++)
	{
		if (a == 0 && b == 0 || i==n)
		{
			sum = i;
			break;
		}
		if (s[i] == 0)
		{
			if (a > 0)
			{
				--a; continue;
			}
			else
			{
				--b; continue;
			}
		}
		else
		{
			if (b > 0 && a < maxa)
			{
				b--; a++; continue;
			}
			else
			{
				--a;
			}
		}
	}
	cout << sum;
	return 0;
}
