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
const unsigned long long HASHBASE = 1222827239ull;
const long long MOD = 1000000007ll;
const double Pi = acos(-1.0);
const double eps = 1e-6;
/////////////////////////
int vis[500010];
int a[500010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    int t=0;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        while(t<n)
        {
            if(a[t] > 0)
            {
                if(vis[a[t]] == 0)
                {
                    ++t;
                }
                else
                {
                    break;
                }
            }
            else
            {
                ++vis[abs(a[t])];
                ++t;
            }
        }
        cout<<t-i<<" ";
        if(a[i] < 0 && vis[abs(a[i])] > 0)
        {
            --vis[abs(a[i])];
        }
    }
    return 0;
}
