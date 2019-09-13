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
    long long r;
    cin>>r;
    long long d1=r*r,d2=4ll*r*r,d3=9ll*r*r,d4=16ll*r*r,d5=25ll*r*r,d6=36ll*r*r,d7=49ll*r*r,d8=64ll*r*r,d9=81ll*r*r,d10=100ll*r*r;;
    long long sum=0;
    for(int i=0;i<3;++i)
    {
        long long x,y;
        cin>>x>>y;
        long long d=x*x+y*y;
        if(d<=d1)
        {
            sum+=10;
        }
        else if(d>d1 && d<=d2)
        {
            sum+=9;
        }
        else if(d>d2 && d<=d3)
        {
            sum+=8;
        }
        else if(d>d3 && d<=d4)
        {
            sum+=7;
        }
        else if(d>d4 && d<=d5)
        {
            sum+=6;
        }
        else if(d>d5 && d<=d6)
        {
            sum+=5;
        }
        else if(d>d6 && d<=d7)
        {
            sum+=4;
        }
        else if(d>d7 && d<=d8)
        {
            sum+=3;
        }
        else if(d>d8 && d<=d9)
        {
            sum+=2;
        }
        else if(d>d9 && d<=d10)
        {
            sum+=1;
        }
    }
    cout<<sum<<endl;
    return 0;
}
