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
int a[100010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);
        int q=a[n-2];
        int k=0;
        for(int i=0;i<n-2;++i)
        {
            if(a[i]>=1 && q > k+1)
            {
                ++k;
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
