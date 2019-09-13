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
    //ios::sync_with_stdio(false); cin.tie(0);
    double x1,y1,r1;
    double x2,y2,r2;
    int q,w,e;
    scanf("%d%d%d",&q,&w,&e);
    x1=q;y1=w;r1=e;
    scanf("%d%d%d",&q,&w,&e);
    x2=q;y2=w;r2=e;
    double rdis = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    double qq = (r1+r2-rdis)/2.0;
    double we = r1-qq;
    double x3 = x1 + we / rdis * (x2-x1);
    double y3 = y1 + we / rdis * (y2-y1);
    printf("%.15f %.15f %.15f",x3,y3,qq);
    return 0;
}
