#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char str[51][51];
	bool is = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}
	for (int i = 0; i < n-2; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (str[i][j] == '.' && str[i + 1][j] == '.' && str[i + 1][j-1] == '.' && str[i + 1][j+1] == '.' && str[i + 2][j] == '.')
			{
				str[i][j] = '#';
				str[i+1][j] = '#';
				str[i+1][j-1] = '#';
				str[i+1][j+1] = '#';
				str[i+2][j] = '#';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[i][j] == '.')is = false;
		}
	}
	if (is)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
