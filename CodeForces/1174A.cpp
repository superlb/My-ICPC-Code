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
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int a[2001];
    int sum=0;
    for(int i=0;i<n*2;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n*2);
    int sum2=0;
    for(int i=0;i<n;++i)
    {
        sum2+=a[i];
    }
    if(sum!=sum2*2)
    {
        for(int i=0;i<n*2;++i)
        {
            cout<<a[i]<<" ";
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
