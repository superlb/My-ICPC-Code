//静态查询第K大的数

int n,m;
const int maxn=200050;
struct Node
{
    int ls,rs;
    int cnt;
}tr[maxn*20];
int cur,rt[maxn];
void init()
{
    cur=0;
}
inline void push_up(int o)
{
    tr[o].cnt=tr[tr[o].ls].cnt+tr[tr[o].rs].cnt;
}
int build(int l,int r)
{
    int k=cur++;
    if (l==r)
    {
        tr[k].cnt=0;
        return k;
    }
    int mid=(l+r)>>1;
    tr[k].ls=build(l,mid);
    tr[k].rs=build(mid+1,r);
    push_up(k);
    return k;
}
int update(int o,int l,int r,int pos,int val)
{
    int k=cur++;
    tr[k]=tr[o];
    if (l==pos&&r==pos)
    {
        tr[k].cnt+=val;
        return k;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) tr[k].ls=update(tr[o].ls,l,mid,pos,val);
    else tr[k].rs=update(tr[o].rs,mid+1,r,pos,val);
    push_up(k);
    return k;
}
int query(int l,int r,int o,int v,int kth)
{
    if (l==r) return l;
    int mid=(l+r)>>1;
    int res=tr[tr[v].ls].cnt-tr[tr[o].ls].cnt;
    if (kth<=res) return query(l,mid,tr[o].ls,tr[v].ls,kth);
    else return query(mid+1,r,tr[o].rs,tr[v].rs,kth-res);
}
int b[maxn];
int sortb[maxn];
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;++i)
    {
        scanf("%d",b+i);
        sortb[i]=b[i];
    }
    sort(sortb+1,sortb+n+1);
    int len=unique(sortb+1,sortb+n+1)-sortb-1;
    rt[0]=build(1,len);
    for(int i=1;i<=n;++i)
    {
        int p=lower_bound(sortb+1,sortb+n+1,b[i])-sortb;
        rt[i]=update(rt[i-1],1,len,p,1);
    }
    for(int i=0;i<m;++i)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int idx=query(1,len,rt[l-1],rt[r],k);
        printf("%d\n",sortb[idx]);
    }
    return 0;
}


//查询区间内有多少个不同的数

const int MAXN=30010;
const int M=MAXN*100;
int n,q,tot;
int a[MAXN],T[MAXN],lson[M],rson[M],c[M];
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else
        {
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int root,int pos)
{
    int ret=0;
    int l=1,r=n;
    while(pos<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            r=mid;
            root=lson[root];
        }
        else
        {
            ret+=c[lson[root]];
            root=rson[root];
            l=mid+1;
        }
    }
    return ret+c[root];
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        tot=0;
        for(int i=1;i<=n;++i)
            scanf("%d",a+i);
        T[n+1]=build(1,n);
        map<int,int> mp;
        for(int i=n;i>=1;--i)
        {
            if(mp.find(a[i])==mp.end())
            {
                T[i]=update(T[i+1],i,1);
            }
            else
            {
                int tmp=update(T[i+1],mp[a[i]],-1);
                T[i]=update(tmp,i,1);
            }
            mp[a[i]]=i;
        }
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(T[l],r));
        }
    }
    return 0;
}


//动态区间第k大

const int MAXN=60010;
const int M=2500010;
int n,q,m,tot;
int a[MAXN],t[MAXN];
int T[MAXN],lson[M],rson[M],c[M];
int S[MAXN];
struct Query
{
    int kind;
    int l,r,k;
}query[10010];
void Init_hash(int k)
{
    sort(t,t+k);
    m=unique(t,t+k)-t;
}
int hash(int x)
{
    return lower_bound(t,t+m,x)-t;
}
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);
    }
    return root;
}
int Insert(int root,int pos,int val)
{
    int newroot =tot++,tmp=newroot;
    int l=0,r=m-1;
    c[newroot]=c[root]+val;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(pos<=mid)
        {
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else
        {
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int lowbit(int x)
{
    return x&(-x);
}
int use[MAXN];
void add(int x,int pos,int val)
{
    while(x<=n)
    {
        S[x] = Insert(S[x],pos,val);
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[lson[use[x]]];
        x-=lowbit(x);
    }
    return ret;
}
int Query(int left,int right,int k)
{
    int left_root=T[left-1];
    int right_root=T[right];
    int l=0,r=m-1;
    for(int i=left-1;i;i-=lowbit(i))use[i]=S[i];
    for(int i=right;i;i-=lowbit(i))use[i]=S[i];
    while(l<r)
    {
        int mid=(l+r)/2;
        int tmp=sum(right)-sum(left-1)+c[lson[right_root]] - c[lson[left_root]];
        if(tmp>=k)
        {
            r=mid;
            for(int i=left-1;i;i-=lowbit(i))
                use[i]=lson[use[i]];
            for(int i=right;i;i-=lowbit(i))
                use[i]=lson[use[i]];
            left_root=lson[left_root];
            right_root=lson[right_root];
        }
        else
        {
            l=mid+1;
            k-=tmp;
            for(int i=left-1;i;i-=lowbit(i))
                use[i]=rson[use[i]];
            for(int i=right;i;i-=lowbit(i))
                use[i]=rson[use[i]];
            left_root=rson[left_root];
            right_root=rson[right_root];
        }
    }
    return l;
}
void Modify(int x,int p,int d)
{
    while(x<=n)
    {
        S[x]=Insert(S[x],p,d);
        x+=lowbit(x);
    }
}
int main()
{
    int Tcase;
    cin>>Tcase;
    while(Tcase--)
    {
        cin>>n>>q;
        tot=0;
        m=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            t[m++]=a[i];
        }
        char op[10];
        for(int i=0;i<q;++i)
        {
            cin>>op;
            if(op[0]=='Q')
            {
                query[i].kind=0;
                cin>>query[i].l>>query[i].r>>query[i].k;
            }
            else
            {
                query[i].kind=1;
                cin>>query[i].l>>query[i].r;
                t[m++]=query[i].r;
            }
        }
        Init_hash(m);
        T[0]=build(0,m-1);
        for(int i=1;i<=n;++i)
            T[i]=Insert(T[i-1],hash(a[i]),1);
        for(int i=1;i<=n;++i)
            S[i]=T[0];
        for(int i=0;i<q;++i)
        {
            if(query[i].kind==0)
            {
                cout<<t[Query(query[i].l,query[i].r,query[i].k)]<<endl;
            }
            else
            {
                Modify(query[i].l,hash(a[query[i].l]),-1);
                Modify(query[i].l,hash(a[query[i].r]),1);
                a[query[i].l]=query[i].r;
            }
        }
    }
}
