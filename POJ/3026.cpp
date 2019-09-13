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
int moved[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int cost[110][110];
string str[100];
int t[100][100];
int a[100][100];
int tot;
void bfs(int sx,int sy)
{
    queue< pair<int,int> > q;
    memset(t,-1,sizeof(t));
    t[sx][sy]=0;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        pair<int,int> now = q.front();q.pop();
        if(a[now.first][now.second]!=-1)
            cost[a[sx][sy]][a[now.first][now.second]]=t[now.first][now.second];
        for(int i=0;i<4;++i)
        {
            int newx=now.first+moved[i][0];
            int newy=now.second+moved[i][1];
            if(str[newx][newy]=='#'||t[newx][newy]!=-1)continue;
            t[newx][newy]=t[now.first][now.second]+1;
            q.push(make_pair(newx,newy));
        }
    }
}
bool vis[110];
int lowc[110];
int Prim(int n)
{
    int ans=0;
    memset(vis,false,sizeof(vis));
    vis[0]=true;
    for(int i=1;i<n;++i)lowc[i]=cost[0][i];
    for(int i=1;i<n;++i)
    {
        int minc=INF;
        int p=-1;
        for(int j=0;j<n;++j)
        {
            if(!vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(minc==INF)return -1;
        ans+=minc;
        vis[p]=true;
        for(int j=0;j<n;++j)
            if(!vis[j]&&lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
    }
    return ans;
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,x,y;
    cin>>t;
    while(t--)
    {
        memset(a,-1,sizeof(a));
        cin>>x>>y;
        getline(cin,str[0]);
        for(int i=0;i<y;++i)
        {
            getline(cin,str[i]);
        }
        tot=0;
        for(int i=0;i<y;++i)
            for(int j=0;j<x;++j)
                if(str[i][j]=='A'||str[i][j]=='S')
                    a[i][j]=tot++;
        for(int i=0;i<y;++i)
            for(int j=0;j<x;++j)
                if(a[i][j]!=-1)
                    bfs(i,j);
        cout<<Prim(tot)<<endl;
    }
    return 0;
}
