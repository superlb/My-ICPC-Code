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
long double dp[101][101][101];
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    int R,S,P;
    cin>>R>>S>>P;
    dp[R][S][P]=1;
    for(int sum=R+S+P;sum>=0;--sum)
    {
        for(int r=R;r>=0;--r)
        {
            for(int s=S;s>=0;--s)
            {
                int p=sum-r-s;
                if(p<0 || p>P) continue;
                if(s==0 && p==0) continue;
                if(r==0 && p==0) continue;
                if(s==0 && r==0) continue;
                if(r>0) dp[r-1][s][p] += dp[r][s][p]*(r*p)/(r*p+s*r+s*p);
                if(s>0) dp[r][s-1][p] += dp[r][s][p]*(r*s)/(r*p+s*r+s*p);
                if(p>0) dp[r][s][p-1] += dp[r][s][p]*(s*p)/(r*p+s*r+s*p);
            }
        }
    }
    long double ans1=0,ans2=0,ans3=0;
    for(int i=1;i<=R;++i) ans1+=dp[i][0][0];
    for(int i=1;i<=S;++i) ans2+=dp[0][i][0];
    for(int i=1;i<=P;++i) ans3+=dp[0][0][i];
    printf("%.12f %.12f %.12f",(double)ans1,(double)ans2,(double)ans3);
    return 0;
}
