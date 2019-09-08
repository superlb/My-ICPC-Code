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
#include <fstream>
#include <set>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
int n,m,r,c,x,y;
struct node
{
    int x,y,l,r;
};
//int ls[2001][2001];
//int rs[2001][2001];
int huafei[2001][2001];
string str[2001];
void bfs()
{
    deque<node> q;
    q.push_front(node{r-1,c-1,x,y});
    huafei[r-1][c-1] = 0;
    while(!q.empty())
    {
        node cur=q.front();
        q.pop_front();
        if(cur.y + 1< m && str[cur.x][cur.y+1] == '.' && cur.r > 0 &&  huafei[cur.x][cur.y] + 1 < huafei[cur.x][cur.y+1])
        {
            huafei[cur.x][cur.y+1]=huafei[cur.x][cur.y] + 1;
            q.push_back(node{cur.x,cur.y+1,cur.l,cur.r-1});
        }
        if(cur.y > 0 && str[cur.x][cur.y-1] == '.' && cur.l > 0 &&  huafei[cur.x][cur.y] + 1 < huafei[cur.x][cur.y-1])
        {
            huafei[cur.x][cur.y-1]=huafei[cur.x][cur.y] + 1;
            q.push_back(node{cur.x,cur.y-1,cur.l-1,cur.r});
        }
        if(cur.x + 1< n && str[cur.x+1][cur.y] == '.' &&  huafei[cur.x][cur.y]  < huafei[cur.x+1][cur.y])
        {
            huafei[cur.x+1][cur.y]=huafei[cur.x][cur.y];
            q.push_front(node{cur.x+1,cur.y,cur.l,cur.r});
        }
        if(cur.x > 0 && str[cur.x-1][cur.y] == '.' &&  huafei[cur.x][cur.y]  < huafei[cur.x-1][cur.y])
        {
            huafei[cur.x-1][cur.y]=huafei[cur.x][cur.y];
            q.push_front(node{cur.x-1,cur.y,cur.l,cur.r});
        }
    }
}
/////////////////////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>r>>c>>x>>y;
    for(int i=0;i<n;++i)
    {
        cin>>str[i];
    }
    for(int i=0;i<2001;++i)
    {
        for(int j=0;j<2001;++j)
        {
            //ls[i][j]=INF;
            //rs[i][j]=INF;
            huafei[i][j]=INF;
        }
    }
    bfs();
    int ans=0;
    for(int i=0;i<2001;++i)
    {
        for(int j=0;j<2001;++j)
        {
            if(huafei[i][j]!=INF)
                ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}
