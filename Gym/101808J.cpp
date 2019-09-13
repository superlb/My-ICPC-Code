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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int l1,r1,p1,d1;
        int l2,r2,p2,d2;
        int k;
        scanf("%d%d%d%d",&l1,&r1,&p1,&d1);
        scanf("%d%d%d%d",&l2,&r2,&p2,&d2);
        scanf("%d",&k);
        int m1=1,m2=1;
        if(d1==0)
        {
            m1=-1;
        }
        if(d2==0)
        {
            m2=-1;
        }
        if(p1==l1)
            m1=1;
        if(p1==r1)
            m1=-1;
        if(p2==l2)
            m2=1;
        if(p2==r2)
            m2=-1;
        int ans=0;
        for(int i=0;i<k;++i)
        {
            p1+=m1;
            p2+=m2;
            if(p1==p2)
                ++ans;
            if(p1==l1)
                m1=1;
            if(p1==r1)
                m1=-1;
            if(p2==l2)
                m2=1;
            if(p2==r2)
                m2=-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
