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
const long long MODNUM = 1000000007ll;
/////////////////////////
struct node
{
    long long s,e;
}nodes[100001];
bool cmp(const node &a,const node &b)
{
    if(a.s==b.s) return a.e<b.e;
    return a.s<b.s;
}
long long n,x,y;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>x>>y;
    for(long long i=0;i<n;++i)
    {
        cin>>nodes[i].s>>nodes[i].e;
    }
    sort(nodes,nodes+n,cmp);
    long long sum=0;
    multiset<long long> s;
    s.insert(nodes[0].e);
    sum = (x+y*(nodes[0].e-nodes[0].s)%MODNUM)%MODNUM;
    for(int i=1;i<n;++i)
    {
        auto q=s.lower_bound(nodes[i].s);
        --q;
        if( ( nodes[i].s - (*q) )*y <= x && nodes[i].s > (*q))
        {
            sum = (sum + (nodes[i].e - (*q))*y%MODNUM)%MODNUM;
            s.erase(q);
            s.insert(nodes[i].e);
        }
        else
        {
            sum = (sum + (nodes[i].e - nodes[i].s)*y%MODNUM + x)%MODNUM;
            s.insert(nodes[i].e);
        }
    }
    cout<<sum<<endl;
    return 0;
}
