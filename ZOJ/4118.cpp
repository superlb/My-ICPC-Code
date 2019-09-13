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
long long a[100010];
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long ans=0;
        long long sum=0;
        for(int i=0;i<n;++i)
        {
            scanf("%lld",a+i);
            sum+=a[i];
        }
        long long q=sum/n;
        ans+=sum-q*n;
        long long sum2=0;
        for(int i=0;i<n;++i)
        {
            sum2+=abs(q-a[i]);
        }
        ans+=(sum2-ans)/2;
        printf("%lld\n",ans);
    }
    return 0;
}
