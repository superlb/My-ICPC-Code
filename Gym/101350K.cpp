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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long t,a,b,n,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        long long sum[10]={0ll,0ll,0ll,0ll,0ll,0ll,0ll,0ll,0ll,0ll};
        long long pos=-1ll,maxnum=0ll;
        long long qwe;
        for(long long x=1ll;;++x)
        {
            y=a*x*x+b*x;
            if(y<=n)
            {
                long long ans[10]={0ll,0ll,0ll,0ll,0ll,0ll,0ll,0ll,0ll,0ll};
                long long maxans=0ll;
                while(y!=0ll)
                {
                    qwe=y%10ll;
                    ++ans[qwe];
                    maxans=max(maxans,ans[qwe]);
                    y/=10ll;
                }
                for(long long i=0ll;i<10ll;++i)
                {
                    if(ans[i]==maxans)
                    {
                        ++sum[i];
                    }
                }
            }
            else
            {
                break;
            }
        }
        for(long long i=0ll;i<10ll;++i)
        {
            if(sum[i]>maxnum)
            {
                pos=i;maxnum=sum[i];
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}
