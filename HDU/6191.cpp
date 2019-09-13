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
struct tree
{
    tree *next[2];
    tree(){next[1]=NULL;next[0]=NULL;}
};
struct node
{
    int id,u,x;
};
vector<int> g[200010];
int val[200010];
vector<node> qs[200010];
int ans[200010];
tree *root[200010];
int n,q;
void insert(int x,tree *rt)
{
    tree *myroot=rt;
    for(int i=30;i>=0;--i)
    {
        int p=(x>>i)&1;
        if(myroot->next[p]==NULL)
        {
            myroot->next[p]=new tree;
        }
        myroot=myroot->next[p];
    }
}
int query(int x,tree *rt)
{
    tree *myroot=rt;
    int ans=0;
    for(int i=30;i>=0;--i)
    {
        int p=(x>>i)&1;
        if(myroot->next[p^1]==NULL)
        {
            myroot=myroot->next[p];
        }
        else
        {
            ans+=(1<<i);
            myroot=myroot->next[p^1];
        }
    }
    return ans;
}
void deltree(tree *rt)
{
    if(rt->next[0]!=NULL) deltree(rt->next[0]);
    if(rt->next[1]!=NULL) deltree(rt->next[1]);
    delete rt;
}
tree *merge(tree *t1,tree *t2)
{
    if(t1==NULL) return t2;
    if(t2==NULL) return t1;
    t1->next[0]=merge(t1->next[0],t2->next[0]);
    t1->next[1]=merge(t1->next[1],t2->next[1]);
    delete t2;
    return t1;
}
void dfs(int u,int fa)
{
    root[u]=new tree;
    for(int i=0;i<g[u].size();++i)
    {
        int son=g[u][i];
        dfs(son,u);
        merge(root[u],root[son]);
    }
    insert(val[u],root[u]);
    for(int i=0;i<qs[u].size();++i)
    {
        ans[qs[u][i].id]=query(qs[u][i].x,root[u]);
    }
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>>n>>q)
    {
        for(int i=1;i<=n;++i)
        {
            g[i].clear();
            qs[i].clear();
        }
        for(int i=1;i<=n;++i)
        {
            cin>>val[i];
        }
        int qwe,ewq;
        for(int i=2;i<=n;++i)
        {
            cin>>qwe;
            g[qwe].push_back(i);
        }
        for(int i=0;i<q;++i)
        {
            cin>>qwe>>ewq;
            qs[qwe].push_back(node{i,qwe,ewq});
        }
        dfs(1,-1);
        for(int i=0;i<q;++i)
        {
            cout<<ans[i]<<endl;
        }
        deltree(root[1]);
    }
    return 0;
}
