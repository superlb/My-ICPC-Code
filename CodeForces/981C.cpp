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
const long long INF64 = 4e18;
const unsigned long long HASHBASE=1222827239ull;
const long long MOD=1000000007ll;
/////////////////////////
int n,u,v;
vector<int> g[100010];
int cnt=0;
vector<int> ans;
void dfs(int v,int fa)
{
    int len=g[v].size();
    if(len>2) ++cnt;
    if(len==1)
    {
        ans.push_back(v);
        return;
    }
    for(int i=0;i<len;++i)
    {
        if(g[v][i]!=fa)
            dfs(g[v][i],v);
    }
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==2)
    {
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<2<<endl;
        return 0;
    }
    int pos;
    int maxnum=0;
    for(int i=1;i<=n;++i)
    {
        if(g[i].size()>maxnum)
        {
            pos=i;maxnum=g[i].size();
        }
    }
    dfs(pos,-1);
    if(cnt>1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();++i)
        {
            cout<<pos<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}
