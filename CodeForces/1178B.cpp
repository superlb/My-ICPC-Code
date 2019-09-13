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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string str;
    cin>>str;
    long long len=str.length();
    vector<long long> v;
    long long sum=0;
    long long qqq=0;
    long long ans=0;
    for(long long i=0;i<len;++i)
    {
        if(str[i]=='o')
        {
            v.push_back(-1);
        }
        else
        {
            long long leng=1;
            while(i+leng < len && str[i+leng]=='v')
                ++leng;
            i+=leng-1;
            v.push_back(leng-1);
            sum+=leng-1;
        }
    }
    for(long long i=0;i<v.size();++i)
    {
        if(v[i]>=0)
        {
            qqq+=v[i];sum-=v[i];
        }
        else
        {
            ans+=qqq*sum;
        }
    }
    cout<<ans<<endl;
    return 0;
}
