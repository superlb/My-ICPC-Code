//并查集
int par[MAX_N];
int ranks[MAX_N];
void init(int n)
{
    for(int i=0;i<n;i++)
        par[i]=i,ranks[i]=0;
}
int find(int x)
{
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);y=find(y);
    if(x==y)return;
    if(ranks[x]<ranks[y])
        par[x]=y;
    else
    {
        par[y]=x;
        if(ranks[x]==ranks[y]) ranks[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
