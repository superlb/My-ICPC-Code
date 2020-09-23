//求解第k短路
//先dijkstra终点，求出终点到各点的最短路，构造出A*
//然后调用bfs函数，如果第k短路不存在则返回-1
struct edge
{
    long long to,cost;
};
long long V,k;//顶点数，第k短路
vector<edge> G[MAXV];//反向边
vector<edge> G2[MAXV];//正向边
long long d[MAXV];//终点到各个点的最短距离，A*
struct node
{
    long long to,cost;
    bool operator < (const node &a) const
    {
        return a.cost + d[a.to] < cost + d[to];
    }
};
void dijkstra(long long s)
{
    priority_queue< pair<long long,long long> , vector< pair<long long,long long> > ,greater< pair<long long,long long> > > q;
    fill(d,d+V+1,INF);
    d[s]=0;
    q.push( pair<long long,long long>(0,s) );
    while(!q.empty())
    {
        pair<long long,long long> p=q.top();
        q.pop();
        long long v=p.second;
        if(d[v]<p.first)
            continue;
        long long len=G[v].size();
        for(long long i=0;i<len;++i)
        {
            edge e=G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push(pair<long long,long long>(d[e.to],e.to));
            }
        }
    }
}

long long bfs(long long s,long long t)
{
    priority_queue<node> q;
    q.push((node){s,0});
    node n;
    long long len;
    while(!q.empty())
    {
        n=q.top();q.pop();
        if(n.to == t)
        {
            --k;
            if(k==0)
            {
                return n.cost;
            }
        }
        len = G2[n.to].size();
        for(long long i=0;i<len;++i)
        {
            q.push((node){G2[n.to][i].to,G2[n.to][i].cost+n.cost});
        }
    }
    return -1;
}
