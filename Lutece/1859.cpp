#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long rev2 = 500000004;
long long ad(long long a,long long b) {
	return (a+b) % mod;
}
long long mul(long long a,long long b) {
	a %= mod;
	b %= mod;
	return a*b%mod;
}
long long rev6 = 166666668;
int main() {
	long long ans = 0;
	long long N;
	cin >> N;
	for(long long i = 0;i < N;++i) {
		for(long long j = 0;j <= i;++j) {
			ans = ad(ans,mul(mul(mul(mul(i*j,rev2),rev2),rev2),j*j*(j+1)*(j+1)));
			ans = ad(ans,mul(mul(mul(i*j,rev2),j*(j+1)*(2*j+1)),rev6));
		}
	}
	cout << ans << endl;
	return 0;
}
