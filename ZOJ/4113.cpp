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
    //ios::sync_with_stdio(false); cin.tie(0);
    long long t;
    long long y1,m1,d1,y2,m2,d2,sum1,sum2;
    long long q;
    char a[20];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%s",&y1,&m1,&d1,a);
        scanf("%lld%lld%lld",&y2,&m2,&d2);
        sum1=360ll*y1+30ll*m1+d1;
        sum2=360ll*y2+30ll*m2+d2;
        if(a[0]=='M' && a[1]=='o')
        {
            q=1;
        }
        else if(a[0]=='T' && a[1]=='u')
        {
            q=2;
        }
        else if(a[0]=='W' && a[1]=='e')
        {
            q=3;
        }
        else if(a[0]=='T' && a[1]=='h')
        {
            q=4;
        }
        else if(a[0]=='F' && a[1]=='r')
        {
            q=0;
        }
        if(sum2>=sum1)
            q=(q+abs(sum1-sum2))%5;
        else
            q=(q+5-abs(sum1-sum2)%5)%5;
        if(q==1)
        {
            printf("Monday\n");
        }
        else if(q==2)
        {
            printf("Tuesday\n");
        }
        else if(q==3)
        {
            printf("Wednesday\n");
        }
        else if(q==4)
        {
            printf("Thursday\n");
        }
        else if(q==0)
        {
            printf("Friday\n");
        }
    }
    return 0;
}
