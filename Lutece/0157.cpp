#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t, n,a;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a = sqrt(n);
		cout << a * a << endl;
	}
	return 0;
}
