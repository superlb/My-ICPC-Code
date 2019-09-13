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
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    bool is1=false,is2=false;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]%2)
        {
            is1=true;
        }
        else
        {
            is2=true;
        }
    }
    if(is1 && is2)
    {
        sort(a,a+n);
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
