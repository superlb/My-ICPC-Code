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
long long gcd(long long a, long long b)
{
    return (b==0)?a:gcd(b, a % b);
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    string str;
    while(cin>>n>>str)
    {
        long long len=str.length();
        long long a[4]={0,0,0,0};
        long long up=1,down=1;
        for(long long i=0;i<len;++i)
        {
            if(str[i]=='a')
            {
                ++a[0];
            }
            else if(str[i]=='v')
            {
                ++a[1];
            }
            else if(str[i]=='i')
            {
                ++a[2];
            }
            else if(str[i]=='n')
            {
                ++a[3];
            }
        }
        long long sum=a[0]+a[1]+a[2]+a[3];
        up*=a[0];down*=sum;
        up*=a[1];down*=sum;
        up*=a[2];down*=sum;
        up*=a[3];down*=sum;
        long long gcdnum=gcd(up,down);
        cout<<up/gcdnum<<"/"<<down/gcdnum<<endl;
    }
    return 0;
}
