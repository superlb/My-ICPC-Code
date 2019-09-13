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
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    while(cin>>n)
    {
        long long a;
        vector<long long> v(n+2);
        v[0]=0;
        for(long long i=0;i<=n;++i)
        {
            cin>>a;
            v[i+1]=v[i]+a;
        }
        long long sum=v[n+1];
        long long i=0;
        while(sum-v[i] >= i)
            ++i;
        cout<<--i<<endl;
    }
    return 0;
}
