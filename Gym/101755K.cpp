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
int a[200010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int l=0,r=m+1;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]<=sum)
            {
                ++sum;
            }
            else
            {
                if(mid)
                {
                    --mid;
                    ++sum;
                }
            }
        }
        if(sum<m)
            l=(l+r)/2;
        else
            r=(l+r)/2;
    }
    int ans=l;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]<=sum)
        {
            ++sum;
        }
        else
        {
            if(ans)
            {
                --ans;
                ++sum;
            }
        }
    }
    if(sum<m)
        cout<<r<<endl;
    else
        cout<<l<<endl;
    return 0;
}
