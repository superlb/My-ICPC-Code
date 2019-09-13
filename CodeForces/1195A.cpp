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
int b[1010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,a;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ++b[a];
    }
    int sum=0;
    int ans=0;
    for(int i=1;i<=k;++i)
    {
        if(b[i]%2)
        {
            ++sum;
        }
        b[i]/=2;
        ans+=b[i];
    }
    int q=(n+1)/2;
    if(q<=ans)
    {
        cout<<2*q<<endl;
    }
    else
    {
        cout<<2*ans+(q-ans)<<endl;
    }
    return 0;
}
