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
const double Pi = acos(-1.0);
/////////////////////////
const int MAXN=1000010;
int n,m;
struct complex {
    double x, y;
    complex (double xx = 0, double yy = 0) {x = xx, y = yy;}
} a[MAXN], b[MAXN];
complex operator + (complex a, complex b) { return complex(a.x + b.x , a.y + b.y);}
complex operator - (complex a, complex b) { return complex(a.x - b.x , a.y - b.y);}
complex operator * (complex a, complex b) { return complex(a.x * b.x - a.y * b.y , a.x * b.y + a.y * b.x);}
int l, r[MAXN];
int limit = 1;
void fast_fast_tle(complex *A, int type)
{
    for (int i = 0; i < limit; i++)
        if (i < r[i]) swap(A[i], A[r[i]]);
    for (int mid = 1; mid < limit; mid <<= 1)
    {
        complex Wn( cos(Pi / mid) , type * sin(Pi / mid) );
        for (int R = mid << 1, j = 0; j < limit; j += R)
        {
            complex w(1, 0);
            for (int k = 0; k < mid; k++, w = w * Wn)
            {
                complex x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    int qwe;
    for(int i=0;i<n;++i)
    {
        cin>>qwe;
        a[qwe].x=1;
        b[qwe].x=1;
    }
    a[0].x=1;b[0].x=1;
    n=200001;m=200001;
    while (limit <= n + m) limit <<= 1, l++;
    for (int i = 0; i < limit; i++)
        r[i] = ( r[i >> 1] >> 1 ) | ( (i & 1) << (l - 1) ) ;
    fast_fast_tle(a, 1);
    fast_fast_tle(b, 1);
    for (int i = 0; i <= limit; i++) a[i] = a[i] * b[i];
    fast_fast_tle(a, -1);
    cin>>m;
    int ans=0;
    for(int i=0;i<m;++i)
    {
        cin>>qwe;
        if( (int)(a[qwe].x/ limit + 0.5) )
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
