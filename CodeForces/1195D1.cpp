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
const long long INF64 = 1ll << 59;
const unsigned long long HASHBASE=1222827239ull;
const long long MOD=1000000007ll;
/////////////////////////
long long a,w,qwe;
long long n;
long long q[100];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(long long i=0;i<n;++i)
    {
        cin>>a;
        qwe=0;
        while(a!=0)
        {
            w=a%10;
            a/=10;
            for(long long j=0;j<2;++j)
            {
                q[j+qwe]+=w*n;
            }
            qwe+=2;
        }
    }
    qwe=1;
    long long ans=0;
    for(long long i=0;i<99;++i)
    {
        q[i+1]+=q[i]/10;
        q[i]%=10;
        ans = (ans + q[i]*qwe%998244353ll)%998244353ll;
        qwe = qwe*10ll%998244353ll;
    }
    cout<<ans<<endl;
    return 0;
}
