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
long long a[300010];
long long b[300010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin>>n>>k;
    for(long long i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(long long i=1;i<n;++i)
    {
        b[i]=a[i+1]-a[i];
    }
    sort(b+1,b+n+1);
    long long sum=a[n]-a[1];
    for(long long i=0;i<k-1;++i)
    {
        sum-=b[n-i];
    }
    cout<<sum<<endl;
    return 0;
}
