// luogu-judger-enable-o2
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
const int MAXN=10000010;
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
void fast_fast_tle(complex *A, int type) {
    for (int i = 0; i < limit; i++)
        if (i < r[i]) swap(A[i], A[r[i]]); //求出要迭代的序列
    for (int mid = 1; mid < limit; mid <<= 1) { //待合并区间的长度的一半
        complex Wn( cos(Pi / mid) , type * sin(Pi / mid) ); //单位根
        for (int R = mid << 1, j = 0; j < limit; j += R) { //R是区间的长度，j表示前已经到哪个位置了
            complex w(1, 0); //幂
            for (int k = 0; k < mid; k++, w = w * Wn) { //枚举左半部分
                complex x = A[j + k], y = w * A[j + mid + k]; //蝴蝶效应
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
    cin>>n>>m;
    for(int i=0;i<=n;++i) cin>>a[i].x;
    for(int i=0;i<=m;++i) cin>>b[i].x;
    while (limit <= n + m) limit <<= 1, l++;
    for (int i = 0; i < limit; i++)
        r[i] = ( r[i >> 1] >> 1 ) | ( (i & 1) << (l - 1) ) ;
    // 在原序列中 i 与 i/2 的关系是 ： i可以看做是i/2的二进制上的每一位左移一位得来
    // 那么在反转后的数组中就需要右移一位，同时特殊处理一下奇数
    fast_fast_tle(a, 1);
    fast_fast_tle(b, 1);
    for (int i = 0; i <= limit; i++) a[i] = a[i] * b[i];
    fast_fast_tle(a, -1);
    for (int i = 0; i <= n + m; i++)
        cout<<(int)(a[i].x / limit + 0.5)<<" ";
    cout<<endl;
    return 0;
}
