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
const unsigned long long HASHBASE = 1222827239ull;
const long long MOD = 1000000007ll;
const double Pi = acos(-1.0);
const double eps = 1e-6;
/////////////////////////
int vis[10000000];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,p,sum;
    cin>>p>>n;
    vis[0]=1ll;
    for(long long i=1;i<=min(n,10000000ll);++i)
    {
        sum=(i+1ll)*i/2ll;
        vis[sum%p]=1;
    }
    int ans=0;
    for(long long i=0;i<p;++i)
    {
        if(vis[i])
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
