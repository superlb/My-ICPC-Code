//Dijkstra算法，求解单源最短路，仅限正权图
struct edge
{
    int to,cost;
};
int V;
vector<edge> G[MAXV];
int d[MAXV];
void dijkstra(int s)
{
    priority_queue< pair<int,int> , vector< pair<int,int> > ,greater< pair<int,int> > > q;
    fill(d,d+V+1,INF);
    d[s]=0;
    q.push( pair<int,int>(0,s) );
    while(!q.empty())
    {
        pair<int,int> p=q.top();
        q.pop();
        int v=p.second;
        if(d[v]<p.first)
            continue;
        int len=G[v].size();
        for(int i=0;i<len;++i)
        {
            edge e=G[v][i];
            if(d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                q.push(pair<int,int>(d[e.to],e.to));
            }
        }
    }
}
