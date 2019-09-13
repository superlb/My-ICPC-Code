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
const long long INF64 = 4e18;
const unsigned long long HASHBASE=1222827239ull;
const long long MOD=1000000007ll;
/////////////////////////
long long x[200010],y[200010];
long long n;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;++i)
    {
        cin>>x[i]>>y[i];
    }
    x[0]=x[n];y[0]=y[n];
    x[n+1]=x[1];y[n+1]=y[1];
    long long ans=INF64;
    for(long long i=1;i<=n;++i)
    {
        long long d1=x[i]-x[i-1];
        long long d2=x[i]-x[i+1];
        long long d3=y[i]-y[i-1];
        long long d4=y[i]-y[i+1];
        long long sum=abs(d1*d4-d2*d3);
        ans=min(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}
