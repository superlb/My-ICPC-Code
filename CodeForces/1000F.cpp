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
int a[500010];
int n,len,m,lt,rt;
int ans[500010];
int cnt[500010];
int blo[800];
int res=1;
struct query
{
    int l,r,id,block;
    query(){}
    query(int _l,int _r,int _id)
    {
        l=_l;r=_r;id=_id;
        block=l/len;
    }
    bool operator <(const query &a) const
    {
        if(block!=a.block)
            return block<a.block;
        if(block&1)
            return r<a.r;
        return r>a.r;
    }
}q[500010];
void add(int pos)
{
    int x=a[pos];
    ++cnt[x];
    if(cnt[x]==1)
    {
        ++res;
        ++blo[x/len];
    }
    else if(cnt[x]==2)
    {
        --res;
        --blo[x/len];
    }
}
void erase(int pos)
{
    int x=a[pos];
    --cnt[x];
    if(cnt[x]==1)
    {
        ++res;
        ++blo[x/len];
    }
    else if(cnt[x]==0)
    {
        --res;
        --blo[x/len];
    }
}
int getans()
{
    if(res==0) return 0;
    for(int i=0;i<=len;++i)
    {
        if(blo[i]>0)
        {
            for(int j=i*len;;++j)
            {
                if(cnt[j]==1)
                    return j;
            }
        }
    }
}
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    memset(cnt,0,sizeof(cnt));
    memset(blo,0,sizeof(blo));
    scanf("%d",&n);
    len=sqrt(n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&lt,&rt);
        q[i]=query(lt,rt,i);
    }
    sort(q,q+m);
    lt=1;rt=1;
    cnt[a[1]]=1;
    blo[a[1]/800]=1;
    for(int i=0;i<m;++i)
    {
        while(rt<q[i].r) add(++rt);
        while(lt>q[i].l) add(--lt);
        while(rt>q[i].r) erase(rt--);
        while(lt<q[i].l) erase(lt++);
        ans[q[i].id]=getans();
    }
    for(int i=0;i<m;++i)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
