#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int a[4];
	int b[6] = { 4,8,15,16,23,42 };
	cout << "? 1 3" << endl;
	fflush(stdout);
	cin >> a[0];
	cout << "? 3 5" << endl;
	fflush(stdout);
	cin >> a[1];
	cout << "? 2 4" << endl;
	fflush(stdout);
	cin >> a[2];
	cout << "? 4 5" << endl;
	fflush(stdout);
	cin >> a[3];
	do
	{
		if ( b[0]* b[2] == a[0] && b[2] * b[4] == a[1] && b[1] * b[3] == a[2] && b[3] * b[4] == a[3])
		{
			break;
		}
	} while (next_permutation(b,b+6));
	cout << "! " << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << " " << b[5] << endl;
	fflush(stdout);
	//system("pause");
	return 0;
}
