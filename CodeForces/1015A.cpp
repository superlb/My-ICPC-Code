#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

///////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int a[101]={0};
    int n,m,l,r,sum=0;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>l>>r;
        for(int j=l;j<=r;++j)
        {
            ++a[j];
        }
    }
    for(int i=1;i<=m;++i)
    {
        if(a[i]==0)
        {
            ++sum;
        }
    }
    cout<<sum<<endl;
    for(int i=1;i<=m;++i)
    {
        if(a[i]==0)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
