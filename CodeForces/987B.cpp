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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long double x,y;
    cin>>x>>y;
    long double a=y*log(x),b=x*log(y);
    if(fabs(a-b)<0.000001)
    {
        cout<<"="<<endl;
    }
    else if(a>b)
    {
        cout<<">"<<endl;
    }
    else
    {
        cout<<"<"<<endl;
    }
    return 0;
}
