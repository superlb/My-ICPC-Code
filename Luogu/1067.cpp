#include <iostream>
using namespace std;
int main()
{
	int n;
	int xishu[100];
	int j = 0;
	cin >> n;
	for (int i = 0; i <= n; ++i)
	{
		cin >> xishu[i];
	}
	while (xishu[j]==0)
	{
		++j;
	}
	if (xishu[j] == 1)
	{
		cout << "x^" << (n - j);
	}
	else if (xishu[j] == -1)
	{
		cout << "-x^" << (n - j);
	}
	else
	{
		cout << xishu[j]<<"x^" << (n - j);
	}
	++j;
	for (; j < n-1; ++j)
	{
		if (xishu[j] == 0)continue;
		if (xishu[j] > 0)
		{
			if (xishu[j] == 1)
			{
				cout << "+x^" << (n - j);
			}
			else
			{
				cout << "+" << xishu[j] << "x^" << (n - j);
			}
		}
		else
		{
			if (xishu[j] == -1)
			{
				cout << "-x^" << (n - j);
			}
			else
			{
				cout << xishu[j] << "x^" << (n - j);
			}
		}
	}
	if (xishu[n-1] > 0)
	{
		if (xishu[n - 1] == 1)
		{
			cout << "+x";
		}
		else
		{
			cout << "+" << xishu[n-1] << "x";
		}
	}
	else if (xishu[n-1] == 0) {}
	else
	{
		if (xishu[n - 1] == -1)
		{
			cout << "-x";
		}
		else
		{
			cout << xishu[n-1] << "x";
		}
	}
	if (xishu[n] > 0)
	{
		cout << "+" << xishu[n];
	}
	else if (xishu[n] == 0) {}
	else
	{
		cout << xishu[n];
	}
	return 0;
}
