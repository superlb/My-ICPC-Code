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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;

/////////////////////////
long long dp[2][11];
long long is[11][100001];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        memset(dp,0,sizeof(dp));
        memset(is,0,sizeof(is));
        int p,t,maxt=0;
        for(int i=0;i<n;++i)
        {
            cin>>p>>t;
            ++is[p][t];
            maxt=max(t,maxt);
        }
        int posa,posb;
        dp[1][5]=is[5][1];
        dp[1][4]=is[4][1];
        dp[1][6]=is[6][1];
        for(int i=2;i<=maxt;++i)
        {
            if(i%2)
            {
                posa=1;posb=0;
            }
            else
            {
                posa=0;posb=1;
            }
            dp[posa][0]=max({dp[posb][0],dp[posb][1]})+is[0][i];
            dp[posa][1]=max({dp[posb][0],dp[posb][1],dp[posb][2]})+is[1][i];
            dp[posa][2]=max({dp[posb][1],dp[posb][2],dp[posb][3]})+is[2][i];
            dp[posa][3]=max({dp[posb][2],dp[posb][3],dp[posb][4]})+is[3][i];
            dp[posa][4]=max({dp[posb][3],dp[posb][4],dp[posb][5]})+is[4][i];
            dp[posa][5]=max({dp[posb][4],dp[posb][5],dp[posb][6]})+is[5][i];
            dp[posa][6]=max({dp[posb][5],dp[posb][6],dp[posb][7]})+is[6][i];
            dp[posa][7]=max({dp[posb][6],dp[posb][7],dp[posb][8]})+is[7][i];
            dp[posa][8]=max({dp[posb][7],dp[posb][8],dp[posb][9]})+is[8][i];
            dp[posa][9]=max({dp[posb][8],dp[posb][9],dp[posb][10]})+is[9][i];
            dp[posa][10]=max({dp[posb][9],dp[posb][10]})+is[10][i];
        }
        cout<<max({dp[maxt%2][0],dp[maxt%2][1],dp[maxt%2][2],dp[maxt%2][3],dp[maxt%2][4],dp[maxt%2][5],dp[maxt%2][6],dp[maxt%2][7],dp[maxt%2][8],dp[maxt%2][9],dp[maxt%2][10]})<<endl;
    }
    return 0;
}
