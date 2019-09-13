#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,a1=0,a2=0,sum=0,a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 1)
			++a1;
		else
			++a2;
	}
	if (n == 1)
	{
		if (a1 == 1)
		{
			cout << 1;
		}
		else
		{
			cout << 2;
		}
	}
	else if(n == 2)
	{
		if (a1 == a2)
		{
			cout << 2 << " " << 1;
		}
		else if(a1>a2)
		{
			cout << 1 << " " << 1;
		}
		else if (a1 < a2)
		{
			cout << 2 << " " << 2;
		}
	}
	else
	{
		if (a1 == 1)
		{
			cout << 2 << " " << 1 << " ";
			--a2;
			for (int i = 0; i < a2; ++i)
			{
				cout << 2 << " ";
			}
		}
		else if (a1 == 0)
		{
			for (int i = 0; i < a2; ++i)
			{
				cout << 2 << " ";
			}
		}
		else if (a1 == 2)
		{
			cout << 2 << " " << 1 << " ";
			--a2;
			for (int i = 0; i < a2; ++i)
			{
				cout << 2 << " ";
			}
			cout << 1;
		}
		else
		{
			if (a2 > 0)
			{
				cout << 2 << " " << 1 << " ";
				--a2;
				--a1;
				for (int i = 0; i < a2; ++i)
				{
					cout << 2 << " ";
				}
				for (int i = 0; i < a1; ++i)
				{
					cout << 1 << " ";
				}
			}
			else
			{
				for (int i = 0; i < a1; ++i)
				{
					cout << 1 << " ";
				}
			}
		}
	}
	return 0;
}
