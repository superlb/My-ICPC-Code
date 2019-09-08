#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long dp[2][20000001];
long long n,k,now,pre,nownum,sum=0;
string str;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    cin>>str;
    memset(dp,0,sizeof(dp));
    ++dp[0][(str[0] - '0')%k];
    sum+=dp[0][0];
    for(long long i=1;i<n;++i)
    {
        now=i%2;pre=(i+1)%2;
        nownum=str[i] - '0';
        ++dp[now][nownum%k];
        for(long long j=0;j<k;++j)
        {
            dp[now][(j*10+nownum)%k]+=dp[pre][j];
            dp[pre][j]=0;
        }
        sum+=dp[now][0];
    }
    cout<<sum<<endl;
    return 0;
}
