// base on spfa

struct edge{int to,cap,cost,rev;};

int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    while(f>0)
    {
        fill(dist,dist+V+1,INF);
        dist[s]=0;
        bool update=true;
        while(update)
        {
            update=false;
            for(int v=0;v<V;++v)
            {
                if(dist[v]==INF) continue;
                for(int i=0;i<G[v].size();++i)
                {
                    edge &e=G[v][i];
                    if(e.cap>0 && dist[e.to] > dist[e.from] + e.cost)
                    {
                        dist[e.to] = dist[e.from] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update=true;
                    }
                }
            }
        }
        if(dist[t] == INF)
        {
            return -1;
        }
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d = min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}


//base on dijkstra
typedef pair<int,int> P;

struct edge{int to,cap,cost,rev;};

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V+1,INF);
    while(f>0)
    {
        priority_queue<P, vector<P>,greater<P> > que;
        fill(dist,dist+V+1,INF);
        dist[s]=0;
        bool update=true;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top();que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;
            for(int i=0;i<G[v].size();++i)
            {
                edge &e=G[v][i];
                if(e.cap>0 && dist[e.to] > dist[e.from] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[e.from] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t] == INF)
        {
            return -1;
        }
        for(int v=0;v<V;++v) h[v]+=dist[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d = min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*dist[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
