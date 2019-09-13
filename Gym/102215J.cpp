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
vector<long long> v1,v2;
long long vis[500010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    long long a[3];
    cin>>n;
    for(long long i=0;i<n;++i)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        v1.push_back(a[0]+a[1]+2ll);
        v2.push_back(a[0]+a[1]+a[2]);
        vis[i]=a[2];
    }
    sort(v1.begin(),v1.end());
    for(long long i=0;i<n;++i)
    {
        long long qwe = upper_bound(v1.begin(),v1.end(),v2[i]) - v1.begin() - 1;
        if(vis[i]<2ll)
            ++qwe;
        cout<<qwe<<" ";
    }
    return 0;
}
