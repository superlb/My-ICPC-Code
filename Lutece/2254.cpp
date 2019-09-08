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
long long n,k,s,m;
long long a[30];
long long ans=0;
long long pre[1000001];
map<long long,long long> M[30];
void dfs1(long long sum, long long cur, long long cnt)
{
    if(cur == m)
    {
        if(M[cnt].count(sum))
            ++M[cnt][sum];
        else
            M[cnt].insert(make_pair(sum,1));
        return;
    }
    dfs1(sum, cur + 1, cnt);
    if(a[cur] + sum <= s)
        dfs1(sum + a[cur], cur + 1, cnt);
    if(cnt < k && pre[cur] + sum <= s)
        dfs1(sum + pre[cur], cur + 1, cnt + 1);
}
void dfs2(long long sum, long long cur, long long cnt)
{
    if(cur == n)
    {
        for(long long i = 0; i + cnt <=k; ++i)
            if(M[i].count(s-sum))
                ans+=M[i][s-sum];
        return;
    }
    dfs2(sum, cur + 1, cnt);
    if(a[cur] + sum <= s)
        dfs2(sum + a[cur], cur + 1, cnt);
    if(cnt < k && pre[cur] + sum <= s)
        dfs2(sum + pre[cur], cur + 1, cnt + 1);
}
/////////////////////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>s;
    m=n/2;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
        pre[i]=(a[i]+1)*a[i]/2;
    }
    dfs1(0,0,0);
    dfs2(0,m,0);
    cout<<ans<<endl;
    return 0;
}
