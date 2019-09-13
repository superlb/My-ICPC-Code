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
const long long MOD=1000000007ll;
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long t,u,v;
    cin>>t;
    while(t--)
    {
        cin>>u>>v;
        if(u*u > 2ll*v*v)
        {
            cout<<1<<endl;
        }
        else
            cout<<2<<endl;
    }
    return 0;
}
