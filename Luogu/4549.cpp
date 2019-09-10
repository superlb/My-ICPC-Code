#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	return (b == 0) ? a : gcd(b, a % b);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	int a[20];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0)a[i] *= -1;
	}
	int q = gcd(a[0], a[0]);
	for (int i = 1; i < n; i++)
	{
		q = gcd(a[i], q);
	}
	cout << q;
	//system("pause");
	return 0;
}
