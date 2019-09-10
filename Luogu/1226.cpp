#include<bits/stdc++.h>
using namespace std;
long long mod_pow(long long x, long long n, long long mod)
{
	long long res = 1;
	if (n == 0)res = x % mod;
	while (n > 0)
	{
		if (n & 1)res = res * x%mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a<<"^"<<b<<" mod "<<c<<"="<<mod_pow(a, b, c);
	return 0;
}
