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
    long long res=1;
    while (n>0)
    {
        if(n & 1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long w,h;
    cin>>w>>h;
    cout<<mod_pow(2ll,w+h,998244353ll)<<endl;
    return 0;
}
