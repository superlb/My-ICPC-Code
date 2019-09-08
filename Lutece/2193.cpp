#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n,nown=1;
	while (cin >> n)
	{
		if (n == 0)break;
		int d, m ,y;
		int a[13];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; ++i)
		{
			cin >> d >> m >> y;
			++a[m];
		}
		cout << "Case #" << nown << ":" << endl;
		++nown;
		cout << "Jan:";
		for (int i = 0; i < a[1]; ++i)cout << "*";
		cout << endl;
		cout << "Feb:";
		for (int i = 0; i < a[2]; ++i)cout << "*";
		cout << endl;
		cout << "Mar:";
		for (int i = 0; i < a[3]; ++i)cout << "*";
		cout << endl;
		cout << "Apr:";
		for (int i = 0; i < a[4]; ++i)cout << "*";
		cout << endl;
		cout << "May:";
		for (int i = 0; i < a[5]; ++i)cout << "*";
		cout << endl;
		cout << "Jun:";
		for (int i = 0; i < a[6]; ++i)cout << "*";
		cout << endl;
		cout << "Jul:";
		for (int i = 0; i < a[7]; ++i)cout << "*";
		cout << endl;
		cout << "Aug:";
		for (int i = 0; i < a[8]; ++i)cout << "*";
		cout << endl;
		cout << "Sep:";
		for (int i = 0; i < a[9]; ++i)cout << "*";
		cout << endl;
		cout << "Oct:";
		for (int i = 0; i < a[10]; ++i)cout << "*";
		cout << endl;
		cout << "Nov:";
		for (int i = 0; i < a[11]; ++i)cout << "*";
		cout << endl;
		cout << "Dec:";
		for (int i = 0; i < a[12]; ++i)cout << "*";
		cout << endl;
	}
	//system("pause");
	return 0;
}
