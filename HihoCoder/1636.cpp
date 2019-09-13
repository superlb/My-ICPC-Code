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
int dp[110][110][110];
int sum[110][110];
int a[110];
int n,l,r;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>>n>>l>>r)
    {
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;++i)
        {
            sum[i][i-1]=0;
            for(int j=i;j<=n;++j)
            {
                sum[i][j]=sum[i][j-1]+a[j];
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=i;j<=n;++j)
            {
                dp[i][j][j-i+1]=0;
            }
        }
        for(int len=2;len<=n;++len)
        {
            for(int i=1,j=i+len-1;j<=n;++i,++j)
            {
                for(int p=i;p<j;++p)
                {
                    for(int k=1;k<=len;++k)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[i][p][k-1]+dp[p+1][j][1]);
                        if(l<=k && k<=r)
                        {
                            dp[i][j][1]=min(dp[i][j][1],dp[i][j][k]+sum[i][j]);
                        }
                    }
                }
            }
        }
        if(dp[1][n][1]==INF)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<dp[1][n][1]<<endl;
        }
    }
    return 0;
}
