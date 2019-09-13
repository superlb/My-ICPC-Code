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
long long b[100010];
long long a[100010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;++i)
    {
        cin>>b[i];
    }
    if(n<=2)
    {
        cout<<0<<endl;
        return 0;
    }
    long long out=INF64;
    for(long long d1=-1;d1<=1;++d1)
    {
        for(long long d2=-1;d2<=1;++d2)
        {
            a[1]=b[1]+d1;
            a[2]=b[2]+d2;
            long long cnt=abs(d1)+abs(d2);
            for(long long i=3;i<=n+1;++i)
            {
                if(i==n+1)
                {
                    out=min(cnt,out);
                }
                a[i]=a[1]+(i-1)*(a[2]-a[1]);
                if(abs(a[i]-b[i]) > 1) break;
                if(abs(a[i]-b[i]) == 1) ++cnt;
            }
        }
    }
    if(out==INF64)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<out<<endl;
    }
    return 0;
}
