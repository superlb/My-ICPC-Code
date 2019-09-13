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
long long a[200010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin>>n;
    long long x=0,y=0;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<"YES"<<endl;
        cout<<"1 "<<a[0]<<endl;
        return 0;
    }
    for(long long i=0;i<n-1;++i)
    {
        y=max(y, abs(a[i]-a[i+1]) );
    }
    if(y==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    bool is=true;
    long long nowx=(a[0]-1)/y+1;
    x=nowx;
    for(int i=0;i<n-1;++i)
    {
        if(abs(a[i]-a[i+1]) == 1 && y!= 1 )
        {
            if(a[i+1] > nowx*y || a[i] > nowx*y || a[i+1] <= (nowx-1)*y || a[i] <= (nowx-1)*y)
            {
                is=false;
                break;
            }
        }
        else
        {
            if(a[i]>a[i+1])
            {
                if(a[i]-a[i+1] != y)
                {
                    is=false;
                    break;
                }
                else
                {
                    --nowx;
                }
            }
            else
            {
                if(a[i+1]-a[i] != y)
                {
                    is=false;
                    break;
                }
                else
                {
                    ++nowx;
                    x=max(x,nowx);
                }
            }
        }
    }
    if(is)
    {
        cout<<"YES"<<endl;
        cout<<x<<" "<<y<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
