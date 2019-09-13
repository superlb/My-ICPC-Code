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
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
long long c[1010][1010];
long long a[1010];
long long n;
long long dp[1010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    for(long long i=0;i<1010;++i)
    {
        c[i][0]=c[i][i]=1;
        for(long long j=0;j<i;++j)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%998244353;
        }
    }
    cin>>n;
    for(long long i=0;i<n;++i)
        cin>>a[i];
    dp[n]=1;
    for(long long i=n-1;i>=0;--i)
    {
        if(a[i]<=0) continue;
        for(long long j=i+a[i]+1;j<=n;++j)
        {
            dp[i]+=(dp[j]*c[j-i-1][a[i]])%998244353;
            dp[i]%=998244353;
        }
    }
    long long sum=0;
    for(long long i=0;i<n;++i)
    {
        sum+=dp[i];
        sum%=998244353;
    }
    cout<<sum<<endl;
    return 0;
}
