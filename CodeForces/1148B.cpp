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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;

///////////////////////////
long long n,m,ta,tb,k;
long long a[600001];
long long b[600001];
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    fill(a,a+600001,INF);
    fill(b,b+600001,-1);
    cin>>n>>m>>ta>>tb>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]+=ta;
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    long long w,maxnum=0;
    for(long long i=0;i<=k;++i)
    {
        w=lower_bound(b,b+m,a[i])-b;
        if(b[w+k-i]==-1)
        {
            maxnum=-1;break;
        }
        else
        {
            maxnum=max(maxnum,b[w+k-i]+tb);
        }
    }
    cout<<maxnum<<endl;
    return 0;
}
