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
long long a[100010];
long long n,m,k;
struct node
{
    long long u,v;
}nodes[100010];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    for(long long i=0;i<m;++i)
    {
        cin>>a[i];
        nodes[i].u=(a[i]-1ll)/k;
        nodes[i].v=a[i]%k;
        if(nodes[i].v==0) nodes[i].v=k;
    }
    long long nowblock=nodes[0].u;
    long long ans=0,removenum=0,tmp=0;
    for(long long i=0;i<m;++i)
    {
        nodes[i].u-=removenum/k;
        if(nodes[i].v <= removenum%k)
        {
            nodes[i].u--;
            nodes[i].v = nodes[i].v + k - removenum%k;
        }
        else
        {
            nodes[i].v = nodes[i].v - removenum%k;
        }
        if(nodes[i].u==nowblock)
        {
            ++tmp;
        }
        else
        {
            if(tmp)
            {
                ++ans;
                removenum+=tmp;
                nodes[i].u-=tmp/k;
                if(nodes[i].v <= tmp%k)
                {
                    nodes[i].u--;
                    nodes[i].v = nodes[i].v + k - tmp%k;
                }
                nowblock=nodes[i].u;
                tmp=1;
            }
        }
    }
    if(tmp)
        ++ans;
    cout<<ans<<endl;
    return 0;
}
