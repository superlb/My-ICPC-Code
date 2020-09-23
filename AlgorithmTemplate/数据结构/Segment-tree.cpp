//单点修改
long long a[MAXM+5],st[(MAXM<<2)+5];
void build(long long o,long long l,long long r)
{
    if(l==r) st[o]=0;
    else
    {
        long long m=l+((r-l)>>1);　　　　　
        build(o<<1,l,m);　　　　　　　　
        build((o<<1)|1,m+1,r);　　　　　
        st[o]=max(st[o<<1],st[(o<<1)|1]);　　
    }
}
void update(long long o,long long l,long long r,long long ind,long long ans)
{　　
    if(l==r)
    {
        st[o]=ans;
        return;
    }
    long long m=l+((r-l)>>1);
    if(ind<=m)
        update(o<<1,l,m,ind,ans);
    else
        update((o<<1)|1,m+1,r,ind,ans);
    st[o]=max(st[o<<1],st[(o<<1)|1]);
}
int query(long long o,long long l,long long r,long long ql,long long qr)
{
    if(ql>r||qr<l) return -1;
    if(ql<=l&&qr>=r) return st[o];
    long long m=l+((r-l)>>1);
    long long p1=query(o<<1,l,m,ql,qr),p2=query((o<<1)|1,m+1,r,ql,qr);
    return max(p1,p2);
}
//区间加值
long long add[MAXN<<2],st[MAXN<<2],maxnum[MAXN<<2],minnum[MAXN<<2];
void pushup(long long o)
{
    st[o]=st[o<<1]+st[o<<1|1];
    maxnum[o]=max(maxnum[o<<1],maxnum[o<<1|1]);
    minnum[o]=min(minnum[o<<1],minnum[o<<1|1]);
}
void pushdown(long long o,long long l,long long r)
{
    if(add[o])
    {
        add[o<<1]+=add[o];add[o<<1|1]+=add[o];
        long long m=l+((r-l)>>1);
        st[o<<1]+=add[o]*(m-l+1);st[o<<1|1]+=add[o]*(r-m);
        maxnum[o<<1]+=add[o];maxnum[o<<1|1]+=add[o];
        minnum[o<<1]+=add[o];minnum[o<<1|1]+=add[o];
        add[o]=0;
    }
}
void update(long long o,long long l,long long r,long long ql,long long qr,long long addv)
{
    if(ql<=l&&qr>=r)
    {
        add[o]+=addv;
        st[o]+=addv*(r-l+1);
        maxnum[o]+=addv;
        minnum[o]+=addv;
        return;
    }
    pushdown(o,l,r);
    long long m=l+((r-l)>>1);
    if(ql<=m)update(o<<1,l,m,ql,qr,addv);
    if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,addv);
    pushup(o);
}
struct returnvalue
{
    long long ans,maxs,mins;
};
returnvalue query(long long o,long long l,long long r,long long ql,long long qr)
{
    returnvalue qwe;
    qwe.ans=0;
    qwe.maxs=-INF;
    qwe.mins=INF;
    if(ql<=l&&qr>=r)
    {
        qwe.ans=st[o];
        qwe.maxs=maxnum[o];
        qwe.mins=minnum[o];
        return qwe;　
    }
    pushdown(o,l,r);
    long long m=l+((r-l)>>1);
    if(ql<=m)
    {
        returnvalue asd=query(o<<1,l,m,ql,qr);
        qwe.ans+=asd.ans;
        qwe.maxs=max(asd.maxs,qwe.maxs);
        qwe.mins=min(asd.mins,qwe.mins);
    }
    if(qr>=m+1)
    {
        returnvalue asd=query(o<<1|1,m+1,r,ql,qr);
        qwe.ans+=asd.ans;
        qwe.maxs=max(asd.maxs,qwe.maxs);
        qwe.mins=min(asd.mins,qwe.mins);
    }
　　return qwe;
}
//区间改值
void pushup(long long o)
{
     st[o]=st[o<<1]+st[o<<1|1];
}
void pushdown(long long o,long long l,long long r)
{
    if(change[o])
    {
        long long c=change[o];
        change[o<<1]=c;
        change[o<<1|1]=c;
        int m=l+((r-l)>>1);
        st[o<<1]=(m-l+1)*c;
        st[o<<1|1]=(r-m)*c;
        change[o]=0;
    }
}
void update(long long o,long long l,long long r,long long ql,long long qr,long long c)
{
    if(ql<=l&&qr>=r)
    {
        change[o]=c;
        st[o]=(r-l+1)*c;
        return;
    }
    pushdown(o,l,r);
    long long m=l+((r-l)>>1);
    if(ql<=m)update(o<<1,l,m,ql,qr,c);
    if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
    pushup(o);
}
int query(long long o,long long l,long long r,long long ql,long long qr)
{
    if(ql<=l&&qr>=r) return st[o];
    pushdown(o,l,r);
    long long m=l+((r-l)>>1);
    long long ans=0;
    if(ql<=m)ans+=query(o<<1,l,m,ql,qr);
    if(qr>=m+1)ans+=query(o<<1|1,m+1,r,ql,qr);
    return ans;
}
