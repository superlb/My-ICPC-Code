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
struct node
{
    unsigned long long x,y,z,id;
};
bool cmp(node a,node b)
{
    if(a.z*b.y+a.z*b.x==a.x*b.z+a.y*b.z)
        return a.id<b.id;
    return a.z*b.y+a.z*b.x > a.x*b.z+a.y*b.z;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    unsigned long long n;
    while(cin>>n)
    {
        unsigned long long q,w,e;
        vector<node> v;
        for(unsigned long long i=1;i<=n;++i)
        {
            cin>>q>>w>>e;
            v.push_back(node{q,w,e,i});
        }
        sort(v.begin(),v.end(),cmp);
        for(unsigned long long i=0;i<n-1;++i)
        {
            cout<<v[i].id<<" ";
        }
        cout<<v[n-1].id<<endl;
    }
    return 0;
}
