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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
int qqq[1000010];
int jishuqi[5000010];
struct Trie
{
    int next[5000010][26],fail[5000010],end[5000010];
    int root,L;
    int newnode()
    {
        for(int i=0;i<26;++i)
            next[L][i]=-1;
        end[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    int insert(string str)
    {
        int len=str.size();
        int now=root;
        for(int i=0;i<len;++i)
        {
            if(next[now][str[i]-'a'] == -1)
                next[now][str[i]-'a'] = newnode();
            now = next[now][str[i]-'a'];
        }
        end[now]++;
        return now;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for(int i=0;i<26;++i)
        {
            if(next[root][i]==-1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now=Q.front();Q.pop();
            for(int i=0;i<26;++i)
            {
                if(next[now][i]==-1)
                {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    int query(string str)
    {
        int len=str.size();
        int now=root;
        int res=0;
        for(int i=0;i<len;++i)
        {
            now=next[now][str[i]-'a'];
            int temp=now;
            while(temp!=root)
            {
                res += end[temp];
                if(end[temp])
                {
                    jishuqi[temp]++;
                }
                //end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};
Trie ac;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    string tmp,questr;
    cin>>questr;
    cin>>n;
    ac.init();
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        qqq[i]=ac.insert(tmp);
    }
    ac.build();
    ac.query(questr);
    for(int i=0;i<n;++i)
    {
        cout<<jishuqi[qqq[i]]<<endl;
    }
    return 0;
}
