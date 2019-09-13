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
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b, a % b);
}
long long a[100010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long sum=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            sum+=a[i];
        }
        long long gcdnum=a[0];
        for(int i=1;i<n;++i)
        {
            gcdnum = gcd(gcdnum,a[i]);
        }
        cout<<sum<<" "<<gcdnum<<endl;
    }
    return 0;
}
