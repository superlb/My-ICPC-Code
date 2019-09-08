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
/////////////////////////
int n;
struct point
{
    double x,y;
    point(){}
    point(double _x,double _y)
    {
        x=_x;y=_y;
    }
    point operator + (point p)
    {
        return point(x+p.x,y+p.y);
    }
    point operator - (point p)
    {
        return point(x-p.x,y-p.y);
    }
    point operator * (point p)
    {
        return point(x*p.x,y*p.y);
    }
    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
}points[50000];
bool cmp(const point &a,const point &b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
vector<point> convex_hull()
{
    sort(points,points+n,cmp);
    int k=0;
    vector<point> qs(n*2);
    for(int i=0;i<n;++i)
    {
        while(k>1 && (qs[k-1] - qs[k-2]).det(points[i] - qs[k-1]) <= 0) --k;
        qs[k++]=points[i];
    }
    for(int i=n-2,t=k;i>=0;--i)
    {
        while(k>t && (qs[k-1] - qs[k-2]).det(points[i] - qs[k-1]) <= 0) --k;
        qs[k++]=points[i];
    }
    qs.resize(k-1);
    return qs;
}
/////////////////////////

int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>points[i].x>>points[i].y;
    }
    vector<point> qs = convex_hull();
    double res=0;
    for(int i=0;i<qs.size();++i)
    {
        for(int j=0;j<i;++j)
        {
            res = max(res,(qs[i]-qs[j]).dot(qs[i]-qs[j]));
        }
    }
    printf("%.0f\n",res);
    return 0;
}
