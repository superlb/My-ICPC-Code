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

///////////////////////////
long long a[300001],b[300001];
long long n,m;
long long sum=0;
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cin>>m;
    for(long long i=0;i<m;++i)
    {
        cin>>b[i];
        sum-=b[i];
    }
    if(sum!=0)
    {
        cout<<-1;
        return 0;
    }
    long long posa=0,posb=0,res=0;
    while(posa<n)
    {
        res++;
        long long suma=a[posa++],sumb=b[posb++];
        while(suma!=sumb)
        {
            if(suma<sumb)
            {
                suma+=a[posa++];
            }
            else
            {
                sumb+=b[posb++];
            }
        }
    }
    cout<<res;
    return 0;
}
