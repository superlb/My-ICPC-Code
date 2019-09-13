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
const long long MOD=1000000007ll;
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long t,n,k;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>str;
        long long h=0,s=0;
        for(long long i=0;i<n;++i)
        {
            if(str[i]=='L')
            {
                ++h;
            }
            else if(str[i]=='R')
            {
                --h;
            }
            else if(str[i]=='U')
            {
                ++s;
            }
            else if(str[i]=='D')
            {
                --s;
            }
        }
        long long x=(k-1)*h;
        long long y=(k-1)*s;
        long long ans=0;
        for(long long i=0;i<n;++i)
        {
            if(str[i]=='L')
            {
                ++x;
            }
            else if(str[i]=='R')
            {
                --x;
            }
            else if(str[i]=='U')
            {
                ++y;
            }
            else if(str[i]=='D')
            {
                --y;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        x=0;y=0;
        for(long long i=0;i<n;++i)
        {
            if(str[i]=='L')
            {
                ++x;
            }
            else if(str[i]=='R')
            {
                --x;
            }
            else if(str[i]=='U')
            {
                ++y;
            }
            else if(str[i]=='D')
            {
                --y;
            }
            ans=max(ans,abs(x)+abs(y));
        }
        cout<<ans<<endl;
    }
    return 0;
}
