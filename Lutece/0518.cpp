#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t, a, b, c;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b >> c;
		if (a + b == 9)
		{
			if (a + b == c)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
		{
			if (a + b == c)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
	}
	return 0;
}
