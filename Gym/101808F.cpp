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
const long long MOD=7901;
/////////////////////////
int a[1010];
int b[1010];
int jie[1010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n;
    jie[1]=1;
    for(int i=2;i<1010;++i)
    {
        jie[i]=jie[i-1]*i%MOD;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int sum=1;
        int len=unique(a,a+n)-a;
        for(int i=0;i<len;++i)
        {
            int q = upper_bound(b,b+n,a[i]) - lower_bound(b,b+n,a[i]);
            sum = sum * jie[q] % MOD;
        }
        cout<<sum<<endl;
    }
    return 0;
}
