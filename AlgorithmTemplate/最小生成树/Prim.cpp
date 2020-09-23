//Prim算法，用来求解最小生成树
//朴素Prim，复杂度N^2
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;
int prim()
{
    for(int i=0;i<V;++i)
    {
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<V;++u)
        {
            if(!used[u] && (v==-1 || mincost[u]<mincost[v]) ) v=u;
        }
        if(v===1)break;
        res+=mincost[v];
        for(int u=0;u<V;++u)
        {
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
