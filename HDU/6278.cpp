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
const int MAXN=100010;
int tree[20][MAXN];
int sorted[MAXN];
int toleft[20][MAXN];
void build(int l,int r,int dep)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    int same=mid-l+1;
    for(int i=l;i<=r;++i)
        if(tree[dep][i] < sorted[mid])
            same--;
    int lpos=l;
    int rpos=mid+1;
    for(int i=l;i<=r;++i)
    {
        if(tree[dep][i] < sorted[mid])
            tree[dep+1][lpos++] = tree[dep][i];
        else if(tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep+1][lpos++] = tree[dep][i];
            same--;
        }
        else
            tree[dep+1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l-1] + lpos - l;
    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}
int query(int L,int R,int l,int r,int dep,int k)
{
    if(l==r)return tree[dep][l];
    int mid=(L+R)>>1;
    int cnt=toleft[dep][r]-toleft[dep][l-1];
    if(cnt>=k)
    {
        int newl = L + toleft[dep][l-1] - toleft[dep][L-1];
        int newr = newl + cnt - 1;
        return query(L,mid,newl,newr,dep+1,k);
    }
    else
    {
        int newr = r + toleft[dep][R] - toleft[dep][r];
        int newl = newr - (r-l-cnt);
        return query(mid+1,R,newl,newr,dep+1,k-cnt);
    }
}


/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;++i)
        {
            cin>>tree[0][i];
            sorted[i]=tree[0][i];
        }
        sort(sorted+1,sorted+n+1);
        build(1,n,0);
        int s,t,k;
        while(m--)
        {
            cin>>s>>t;
            int l=1,r=t-s+2;
            while(l+1!=r)
            {
                k=(l+r)/2;
                int q=query(1,n,s,t,0,t-s+2-k);
                if(q>=k)
                    l=k;
                else
                    r=k;
            }
            cout<<l<<endl;
        }
    }
    return 0;
}
