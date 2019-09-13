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
int a[100001];
int b[100001];
string str[100001];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;++i)
        {
            cin>>str[i];
            int qwe=0;
            for(int j=0;j<m;++j)
            {
                if(str[i][j]=='.')
                {
                    ++a[j];
                    ++b[i];
                }
            }
        }
        int ans=INF;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(str[i][j]=='.')
                {
                    ans=min(ans,a[j]+b[i]-1);
                }
                else
                {
                    ans=min(ans,a[j]+b[i]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
