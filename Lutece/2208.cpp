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
struct ac
{
    int ch[2000000][26];
    int val[2000000];
    int f[2000000];
    int last[2000000];
    int cnt[1000001];
    int sz;
    ac()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(cnt,0,sizeof(cnt));
    }
    int idx(char c){return c-'a';}
    void insert(string s, int v)
    {
        int u = 0, n = s.length();
        for(int i = 0;i < n;++i)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    int find(string T)
    {
        int n=T.length();
        int j=0;
        for(int i=0;i<n;++i)
        {
            int c=idx(T[i]);
            j=ch[j][c];
            if(val[j])
            {
                int linshi=j;
                while(linshi)
                {
                    ++cnt[val[linshi]];
                    linshi=last[linshi];
                }
            }
            else if(last[j])
            {
                int linshi=last[j];
                while(linshi)
                {
                    ++cnt[val[linshi]];
                    linshi=last[linshi];
                }
            }
        }
    }
    int getFail()
    {
        queue<int> q;
        f[0]=0;
        for(int c=0;c<26;++c)
        {
            int u=ch[0][c];
            if(u)
            {
                f[u]=0;
                q.push(u);
                last[u]=0;
            }
        }
        while(!q.empty())
        {
            int r=q.front();q.pop();
            for(int c=0;c<26;++c)
            {
                int u=ch[r][c];
                if(!u)
                {
                    ch[r][c]=ch[f[r]][c];
                    continue;
                }
                q.push(u);
                int v=f[r];
                while(v && !ch[v][c]) v=f[v];
                f[u]=ch[v][c];
                last[u]=val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
};
ac myac;
/////////////////////////
int pos[100001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string str,tmp;
    map<string,int> mymap;
    int n;
    cin>>str;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>tmp;
        if(mymap.find(tmp) != mymap.end())
        {
            pos[i]=mymap[tmp];
        }
        else
        {
            mymap.insert(make_pair(tmp,i));
            pos[i]=i;
            myac.insert(tmp,pos[i]);
        }
    }
    myac.getFail();
    myac.find(str);
    for(int i=1;i<=n;++i)
    {
        cout<<myac.cnt[pos[i]]<<endl;
    }
    return 0;
}
