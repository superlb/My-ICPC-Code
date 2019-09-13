#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	bool is = false;
	int max1 = 0, pos = -1, a = -1, n;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= max1)
		{
			pos = i;
			max1 = str[i];
		}
		else
		{
			is = true;
			a = i;
			break;
		}
	}
	if (is)
	{
		cout << "YES" << endl;
		cout << pos+1 << " " << a+1;
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
