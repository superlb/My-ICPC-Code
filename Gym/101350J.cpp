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
    int t;
    double l,ang;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&l);
        scanf("%lf",&ang);
        double cir=Pi*l*l*ang/360.0;
        double tri=l*l*sin(ang*Pi/180.0)/2.0;
        printf("%.6f\n",cir-tri);
    }
    return 0;
}
