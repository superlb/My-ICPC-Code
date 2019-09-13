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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin>>n>>k;
    for(long long i=1ll;i<=n;++i)
    {
        long long sum=i*(i+1ll)/2ll;
        if(n-i==sum-k)
        {
            cout<<n-i<<endl;
            return 0;
        }
    }
    return 0;
}
