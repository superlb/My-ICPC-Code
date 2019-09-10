// luogu-judger-enable-o2
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
const long long MOD=1000000007ll;
/////////////////////////
const int MAXN=100010;
int a[MAXN];
int dp[MAXN][20];
int mm[MAXN];
void initRMQ(int n,int b[])
{
    mm[0]=-1;
    for(int i=1;i<=n;++i)
    {
        mm[i]=((i&(i-1)) == 0)?mm[i-1]+1:mm[i-1];
        dp[i][0]=b[i];
    }
    for(int j=1;j<=mm[n];++j)
        for(int i=1;i+(1<<j)-1<=n;++i)
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int x,int y)
{
    int k=mm[y-x+1];
    return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
    }
    initRMQ(n,a);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",rmq(l,r));
    }
    return 0;
}
