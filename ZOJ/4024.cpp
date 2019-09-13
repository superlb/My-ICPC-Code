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
long long a[100010];
int t,n;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long pos,maxnum=0;
        bool is=true;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            if(a[i]>maxnum)
            {
                pos=i;
                maxnum=a[i];
            }
        }
        for(int i=0;i<pos;++i)
        {
            if(a[i]>=a[i+1])
            {
                is=false;
            }
        }
        for(int i=pos;i<n-1;++i)
        {
            if(a[i]<=a[i+1])
            {
                is=false;
            }
        }
        if(is && pos!=n-1 && pos!=0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
