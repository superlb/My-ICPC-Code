//LCA，最近公共祖先
//预处理复杂度NlogN，每次查询复杂度logN
vector<int> G[MAXN];
int root;
int parent[MAXLOGN][MAXN];
int depth[MAXN];
void dfs(int v,int p,int d)
{
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();++i)
    {
        if(G[v][i]!=p)
            dfs(G[v][i],v,d+1);
    }
}
void init(int V)
{
    dfs(root,-1,0);
    for(int k=0;k+1<MAXLOGN;++k)
    {
        for(int v=0;v<V;++v)
        {
            if(parent[k][v]<0)
                parent[k+1][v]=-1;
            else
                parent[k+1][v]=parent[k][parent[k][v]];
        }
    }
}
int lca(int u,int v)
{
    if(depth[u]>depth[v])swap(u,v);
    for(int k=0;k<MAXLOGN;++k)
    {
        if((depth[v]-depth[u]) >> k & 1)
            v=parent[k][v];
    }
    if(u==v)return u;
    for(int k=MAXLOGN-1;k>=0;--k)
    {
        if(parent[k][u]!=parent[k][v])
        {
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
