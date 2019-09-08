#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n,a=1;
	cin >> n;
	while (((a + 1)*a / 2) % n != 0)
	{
		++a;
	}
	cout << a;
	return 0;
}
