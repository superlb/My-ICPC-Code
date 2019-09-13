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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;

/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    if(n==2)
    {
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<1<<" "<<2<<endl;
        return 0;
    }
    if(n==3)
    {
        cout<<2<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<2<<" "<<2<<endl;
        return 0;
    }
    int len=(n+2)/2;
    cout<<len<<endl;
    for(int i=1;i<=len;++i)
    {
        cout<<1<<" "<<i<<endl;
    }
    for(int i=2;i<=n-len+1;++i)
    {
        cout<<len<<" "<<i<<endl;
    }
    return 0;
}
