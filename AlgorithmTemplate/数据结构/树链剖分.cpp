/*
操作1： 格式： 1 x y z 表示将树从x到y结点最短路径上所有节点的值都加上z

操作2： 格式： 2 x y 表示求树从x到y结点最短路径上所有节点的值之和

操作3： 格式： 3 x z 表示将以x为根节点的子树内所有节点值都加上z

操作4： 格式： 4 x 表示求以x为根节点的子树内所有节点值之和
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2*1e6+10;
#define ls k<<1
#define rs k<<1|1
struct node
{
    int u,v,nxt;
}edge[MAXN];
int head[MAXN];
int num=1;
struct Tree
{
    int l,r,w,siz,f;
}T[MAXN];
int N,M,root,MOD,cnt=0,a[MAXN],b[MAXN];
inline void AddEdge(int x,int y)
{
    edge[num].u=x;
    edge[num].v=y;
    edge[num].nxt=head[x];
    head[x]=num++;
}
int deep[MAXN],fa[MAXN],son[MAXN],tot[MAXN],top[MAXN],idx[MAXN];
int dfs1(int now,int f,int dep)
{
    deep[now]=dep;
    fa[now]=f;
    tot[now]=1;
    int maxson=-1;
    for(int i=head[now];i!=-1;i=edge[i].nxt)
    {
        if(edge[i].v==f) continue;
        tot[now]+=dfs1(edge[i].v,now,dep+1);
        if(tot[edge[i].v]>maxson) maxson=tot[edge[i].v],son[now]=edge[i].v;
    }
    return tot[now];
}
void update(int k)
{
    T[k].w=(T[ls].w+T[rs].w+MOD)%MOD;
}
void Build(int k,int ll,int rr)
{
    T[k].l=ll;T[k].r=rr;T[k].siz=rr-ll+1;
    if(ll==rr)
    {
        T[k].w=a[ll];
        return ;
    }
    int mid=(ll+rr)>>1;
    Build(ls,ll,mid);
    Build(rs,mid+1,rr);
    update(k);
}
void dfs2(int now,int topf)
{
    idx[now]=++cnt;
    a[cnt]=b[now];
    top[now]=topf;
    if(!son[now]) return ;
    dfs2(son[now],topf);
    for(int i=head[now];i!=-1;i=edge[i].nxt)
        if(!idx[edge[i].v])
            dfs2(edge[i].v,edge[i].v);
}
void pushdown(int k)
{
    if(!T[k].f) return ;
    T[ls].w=(T[ls].w+T[ls].siz*T[k].f)%MOD;
    T[rs].w=(T[rs].w+T[rs].siz*T[k].f)%MOD;
    T[ls].f=(T[ls].f+T[k].f)%MOD;
    T[rs].f=(T[rs].f+T[k].f)%MOD;
    T[k].f=0;
}
void IntervalAdd(int k,int ll,int rr,int val)
{
    if(ll<=T[k].l&&T[k].r<=rr)
    {
        T[k].w+=T[k].siz*val;
        T[k].f+=val;
        return ;
    }
    pushdown(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(ll<=mid)    IntervalAdd(ls,ll,rr,val);
    if(rr>mid)    IntervalAdd(rs,ll,rr,val);
    update(k);
}
void TreeAdd(int x,int y,int val)
{
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        IntervalAdd(1,idx[ top[x] ],idx[x],val);
        x=fa[ top[x] ];
    }
    if(deep[x]>deep[y])    swap(x,y);
    IntervalAdd(1,idx[x],idx[y],val);
}
int IntervalSum(int k,int ll,int rr)
{
    int ans=0;
    if(ll<=T[k].l&&T[k].r<=rr)
        return T[k].w;
    pushdown(k);
    int mid=(T[k].l+T[k].r)>>1;
    if(ll<=mid) ans=(ans+IntervalSum(ls,ll,rr))%MOD;
    if(rr>mid)  ans=(ans+IntervalSum(rs,ll,rr))%MOD;
    return ans;
}
int TreeSum(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(deep[top[x]]<deep[top[y]]) swap(x,y);
        ans=(ans+IntervalSum(1,idx[ top[x] ],idx[x]))%MOD;
        x=fa[ top[x] ];
    }
    if(deep[x]>deep[y]) swap(x,y);
    ans=(ans+IntervalSum(1,idx[x],idx[y]))%MOD;
    return ans;
}
int main()
{
    memset(head,-1,sizeof(head));
    cin>>N>>M>>root>>MOD;
    for(int i=1;i<=N;i++) cin>>b[i];
    int o,x,y,z;
    for(int i=1;i<=N-1;i++)
    {
        cin>>x>>y;
        AddEdge(x,y);AddEdge(y,x);
    }
    dfs1(root,0,1);
    dfs2(root,root);
    Build(1,1,N);
    while(M--)
    {
        cin>>o;
        if(o==1)
        {
            cin>>x>>y>>z;
            z=z%MOD;
            TreeAdd(x,y,z);
        }
        else if(o==2)
        {
            cin>>x>>y;
            cout<<TreeSum(x,y)<<endl;
        }
        else if(o==3)
        {
            cin>>x>>z;
            IntervalAdd(1,idx[x],idx[x]+tot[x]-1,z%MOD);
        }
        else if(o==4)
        {
            cin>>x;
            cout<<IntervalSum(1,idx[x],idx[x]+tot[x]-1)<<endl;
        }
    }
    return 0;
}
