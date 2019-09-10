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
int n;
double L,R;
double a[15];
double solve(double x)
{
    double sum=0;
    for(int i=n;i>=0;--i)
    {
        sum = sum*x+a[i];
    }
    return sum;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>L>>R;
    for(int i=n;i>=0;--i)
    {
        cin>>a[i];
    }
    while(fabs(R-L)>=eps)
    {
        double mid=(L+R)/2.0;
        if(solve(mid+eps) > solve(mid-eps)) L=mid;
        else R=mid;
    }
    printf("%.5lf",R);
    return 0;
}
