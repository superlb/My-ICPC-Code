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

////////
int a[100001];
int solve(int q)
{
    for(int i=2;i*i<=q;++i)
    {
        if(q%i==0)
        {
            return i;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    memset(a,0,sizeof(a));
    a[2]=1;
    int n,tot=2,q;
    cin>>n;
    for(int i=3;i<=n;++i)
    {
        q=solve(i);
        if(q==1)
        {
            a[i]=tot++;
        }
        else
        {
            a[i]=a[q];
        }
    }
    for(int i=2;i<=n;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
