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
unsigned long long myhash(char *str)
{
    unsigned long long len =strlen(str);
    unsigned long long sum=0;
    for(unsigned long long i=0;i<len;++i)
    {
        sum=sum*HASHBASE+str[i];
    }
    return sum;
}
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    int t,c,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&c,&n);
        map<unsigned long long,double> m;
        double qqq;
        char str[100];
        for(int i=0;i<c;++i)
        {
            scanf("%s",str);
            scanf("%lf",&qqq);
            m[myhash(str)]=qqq;
        }
        double sum=0.0;
        for(int i=0;i<n;++i)
        {
            scanf("%lf",&qqq);
            scanf("%s",str);
            if(str[0] == 'J' && str[1] == 'D' && str[2] == 0)
            {
                sum+=qqq;
            }
            else
            {
                sum+=qqq*m[myhash(str)];
            }
        }
        printf("%.6lf\n",sum);
    }
    return 0;
}
