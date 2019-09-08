#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int red[501][501];
int black[501][501];
int dp[501][501];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,linshi;
    memset(red,0,sizeof(red));
    memset(black,0,sizeof(black));
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>linshi;
            red[i][j]=linshi+red[i][j-1];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>linshi;
            black[i][j]=linshi+black[i-1][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dp[i][j]=max(dp[i-1][j]+red[i][j],dp[i][j-1]+black[i][j]);
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
