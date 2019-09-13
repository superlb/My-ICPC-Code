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
int a[3010],b[3010],c[3010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            c[a[i]]=i;
        }
        for(int i=1;i<=n;++i)
        {
            cin>>b[i];
            b[i] = c[b[i]];
        }
        int ans=0;
        for(int i=1;i<n;++i)
        {
            int minnum=b[i],maxnum=b[i];
            for(int j=i+1;j<=n;++j)
            {
                minnum=min(minnum,b[j]);
                maxnum=max(maxnum,b[j]);
                if(maxnum-minnum==j-i)
                    ++ans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
