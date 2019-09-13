#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE = 1222827239ull;
const long long MOD = 1000000007ll;
const double Pi = acos(-1.0);
const double eps = 1e-6;
/////////////////////////
long long mod_pow(long long x,long long n,long long mod)
{
    long long res=1ll;
    while (n>0ll)
    {
        if(n & 1ll)res=res*x%mod;
        x=x*x%mod;
        n>>=1ll;
    }
    return res;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin>>n>>k;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
    long long sum1 = n % MOD * mod_pow(2ll,k,MOD) % MOD;
    long long sum2 = (n-1ll) % MOD * mod_pow(2ll,k,MOD) % MOD + 1ll;
    cout<<(sum1+sum2) % MOD<<endl;
    return 0;
}
