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
const long long INF64 = 1ll << 59;
const unsigned long long HASHBASE=1222827239ull;
const long long MOD=1000000007ll;
/////////////////////////
long long dp[100010][2];
long long a[100010];
long long b[100010];
long long n;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(long long i=0;i<n;++i)
    {
        cin>>b[i];
    }
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    for(long long i=1;i<n;++i)
    {
        dp[i][0]=max(dp[i-1][1]+a[i],dp[i-1][0]);
        dp[i][1]=max(dp[i-1][0]+b[i],dp[i-1][1]);
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    return 0;
}
