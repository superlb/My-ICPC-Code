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
const long long MODNUM=1000000007ll;
/////////////////////////
long long solve(long long sum,long long a,long long q)
{
    if(sum==0ll || a==0ll || q==0ll)return 0ll;
    sum=abs(sum);
    long long w=sum/a;
    return min( w*q+solve(sum-w*a,(a-1ll)/10ll,q-1ll), (w+1ll)*q+solve(sum-(w+1ll)*a,(a-1ll)/10ll,q-1ll) );
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin>>n;
    long long a=1ll,q=1ll;
    while(a<=n)
    {
        a*=10ll;++a;++q;
    }
    cout<<solve(n,a,q)<<endl;
    return 0;
}
