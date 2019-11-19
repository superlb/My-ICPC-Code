#include <iostream>
using namespace std;
int main()
{
	long m, n, m1;
	bool isboss = true;
	int a[100000];
	int max = 0;
	long themax;
	bool skip = true;
	cin >> m >> n;
	m1 = m;
	for (long i = 0; i < n - 1; ++i)
	{
		cin >> a[i];
		if (m > a[i])
		{
			m -= a[i];
			m += 6;
			if (a[i] > max)
			{
				max = a[i];
				themax = i;
			}
		}
		else
		{
			if (skip)
			{
				m += 6;
				skip = false;
				continue;
			}
			else
			{
				isboss = false;
				for (long i1 = i + 1; i1 < n; ++i1)
				{
					cin >> a[i1];
				}
				break;
			}
		}
	}
	if (isboss)
	{
		int boss;
		cin >> boss;
		if (m > boss)
		{
			cout << "YES";
		}
		else
		{
			if (m + max > boss && skip)
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
		}
	}
	else
	{
		bool again = true;
		skip = true;
		for (long i = 0; i < n - 1; ++i)
		{
			if (i == themax && skip)
			{
				m1 += 6;
				skip = false;
				continue;
			}
			if (m1 > a[i])
			{
				m1 -= a[i];
				m1 += 6;
			}
			else
			{
				if (skip)
				{
					m1 += 6;
					skip = false;
					continue;
				}
				else
				{
					again = false;
					break;
				}
			}
		}
		if (again)
		{
			if (m1 > a[n - 1])
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
		}
		else
		{
			cout << "NO";
		}
	}
	return 0;
}
