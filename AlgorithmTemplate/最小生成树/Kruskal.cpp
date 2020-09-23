//Kruskal算法，最小生成树
//复杂度ElogE
struct edge
{
    int u,v,cost;
    edge(){}
    edge(int _u,int _v,int _cost)
    {
        u=_u;v=_v;cost=_cost;
    }
    bool operator < (const edge &a) const
    {
        return cost > a.cost;
    }
};
priority_queue<edge> edges;
int kruskal()
{
    init(n);
    int sum=0;
    int len=edges.size();
    edge tmp;
    for(int i=0;i<len;++i)
    {
        tmp=edges.top();edges.pop();
        if(!same(tmp.u,tmp.v))
        {
            unite(tmp.u,tmp.v);
            sum+=tmp.cost;
        }
    }
    return sum;
}
