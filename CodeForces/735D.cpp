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
long long dp[50000];
bool is_prime(long long a)
{
    for (long long i = 2;i * i <= a;i++)
    {
        if (a % i == 0)return false;
    }
    return a != 1;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    for(long long i=2;i<50000;++i)
    {
        if(is_prime(i))
        {
            dp[i]=1;
            continue;
        }
        for(long long j=2;j<i-1;++j)
        {
            if(dp[i]==2) break;
            dp[i]=min(dp[i],dp[j]+dp[i-j]);
        }
    }
    long long a;
    cin>>a;
    if(a<50000)
    {
        cout<<dp[a]<<endl;
        return 0;
    }
    if(is_prime(a))
    {
        cout<<1<<endl;
        return 0;
    }
    long long ans=INF;
    for(long long i=a-2;49900>a-i;--i)
    {
        if(is_prime(i))
        {
            ans=min(ans,1+dp[a-i]);
        }
        if(ans==2)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
