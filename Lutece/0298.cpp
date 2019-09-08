#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string str;
	int t,len,a,b;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> str;
		len = str.length();
		a = len % 3;
		b = len / 3;
		if (a)
		{
			cout << str.substr(0,a);
		}
		else
		{
			cout << str.substr(0, 3);
			a = 3;
			b--;
		}
		while (b-- > 0)
		{
			cout << "," << str.substr(a, 3);
			a += 3;
		}
		cout << endl;
	}
	return 0;
}
