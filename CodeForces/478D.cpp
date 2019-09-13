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
const long long MODNUM=1000000007ll;
/////////////////////////
long long dp[200050];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long r,g;
    cin>>r>>g;
    long long h=1;
    while((h+1)*h/2<=r+g)
    {
        ++h;
    }
    --h;
    long long ans=0;
    long long gg=(h+1)*h/2-g;
    dp[0]=1;
    for(long long i=1;i<=h;++i)
    {
        for(long long j=r;j>=0;--j)
        {
            if(j >= i)
                dp[j]=(dp[j-i]+dp[j])%MODNUM;
            if(j >= gg && i==h)
                ans=(ans+dp[j])%MODNUM;
        }
    }
    cout<<ans<<endl;
    return 0;
}
