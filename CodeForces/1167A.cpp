#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	string str;
	int n,len;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> len >> str;
		if (len - str.find('8') >= 11 && str.find('8') != -1)
		{
			cout << "YES"<<endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	//system("pause");
	return 0;
}
