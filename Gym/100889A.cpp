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
long long a[1010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(long long i=0;i<n;++i)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        long long sum=0;
        for(long long i=0;i<n/2;++i)
        {
            sum+=a[n-i-1]-a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
