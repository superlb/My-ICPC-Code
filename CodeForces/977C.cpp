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
const long long MODNUM=1000000007ll;
/////////////////////////
int a[200010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(k==0)
    {
        if(a[0]==1)
            cout<<-1<<endl;
        else
            cout<<a[0]-1<<endl;
        return 0;
    }
    if(a[k-1]!=a[k])
    {
        cout<<a[k-1]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}
