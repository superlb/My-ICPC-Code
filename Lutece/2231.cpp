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
    int t,tmp;
    while(cin>>t)
    {
        int a[1001];
        int cha;
        a[0]=0;
        for(int i=1;i<=t;++i)
        {
            cin>>a[i];
        }
        cha=a[t]-a[t-1];
        for(int i=t;i>=0;--i)
        {
            if(i==0)
            {
                cout<<1<<endl;
                break;
            }
            if(a[i]-a[i-1] != cha)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
