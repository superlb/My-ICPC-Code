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
long long f[600010],p[600010];
long long extgcd(long long a, long long b, long long& x, long long& y)
{
    long long d = a;
    if (b != 0)
    {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;y = 0;
    }
    return d;
}
long long mod_reverse(long long a,long long n)
{
    long long x,y;
    long long d=extgcd(a,n,x,y);
    if(d==1) return (x%n+n)%n;
    else return -1;
}
long long C(long long a,long long b)
{
    long long up=f[a];
    long long down=f[a-b]*f[b]%MODNUM;
    return up*mod_reverse(down,MODNUM)%MODNUM;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    p[0]=f[0]=1ll;
    for(long long i=1;i<600010ll;++i)
    {
        p[i]=p[i-1]*2ll%MODNUM;
        f[i]=f[i-1]*i%MODNUM;
    }
    long long n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long ans=0;
        for(long long x=0;x<=n;++x)
        {
            long long y=n-x-m-x;
            long long z=m+x;
            if(y<0 || y>n) continue;
            if(z<0 || z>n) continue;
            long long up=C(n,x)*C(n-x,y)%MODNUM;
            long long down=p[2*(x+z)+y];
            ans=(ans+up*mod_reverse(down,MODNUM)%MODNUM)%MODNUM;
        }
        cout<<ans<<endl;
    }
    return 0;
}
