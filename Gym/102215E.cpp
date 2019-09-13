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
const unsigned long long HASHBASE = 1222827239ull;
const long long MOD = 1000000007ll;
const double Pi = acos(-1.0);
const double eps = 1e-6;
/////////////////////////
struct node
{
    int l,r,id;
}nodes[200010];
bool cmp(const node &a,const node &b)
{
    if(a.l==b.l)
        return a.r>b.r;
    return a.l<b.l;
}
struct qqq
{
    int s,id;
    bool operator < (const qqq &a) const
    {
        return s<a.s;
    }
};
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int u,v;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>u>>v;
        nodes[i] = (node){u,v,i+1};
    }
    sort(nodes,nodes+n,cmp);
    priority_queue<qqq> pq;
    vector<int> ans;
    bool is=true;
    int q=nodes[0].l,w=nodes[0].r;
    ans.push_back(nodes[0].id);
    for(int i=1;i<n;++i)
    {
        if(nodes[i].l<=w+1)
        {
            pq.push( (qqq){nodes[i].r,nodes[i].id} );
        }
        else if(nodes[i].l>w+1)
        {
            if(!pq.empty())
            {
                qqq tmp = pq.top();pq.pop();
                w = tmp.s;
                ans.push_back(tmp.id);
                if(nodes[i].l>w+1)
                {
                    is=false;
                    break;
                }
                else
                {
                    pq.push( (qqq){nodes[i].r,nodes[i].id} );
                }
            }
            else
            {
                is=false;
                break;
            }
        }
    }
    if(w!=m && !pq.empty())
    {
        qqq tmp = pq.top();pq.pop();
        w = tmp.s;
        ans.push_back(tmp.id);
    }
    if(is && q==1 && w==m)
    {
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();++i)
        {
            cout<<ans[i]<<" ";
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
