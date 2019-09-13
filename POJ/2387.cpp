#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;

///////////////////////////
struct edge
{
        int to,cost;
};
int V,t;
const int MAXV = 1001;
const int INF = 1<<30;
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
////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>t>>V;
    int x,y,z;
    for(int i=0;i<t;++i)
    {
        cin>>x>>y>>z;
        G[x].push_back((edge){y,z});
        G[y].push_back((edge){x,z});
    }
    dijkstra(1);
    cout<<d[V]<<endl;
    return 0;
}
