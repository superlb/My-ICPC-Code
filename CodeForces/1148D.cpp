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
const long long INF = 1ll << 50;

///////////////////////////

////////
struct node
{
    long long u,v,bianhao;
};
vector<node> n1;
vector<node> n2;
vector<node> s1;
vector<node> s2;
vector<long long> q1;
vector<long long> q2;
long long n,q,w;
bool cmp1(const node &a,const node &b)
{
    return a.v<b.v;
}
bool cmp2(const node &a,const node &b)
{
    return a.v>b.v;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(long long i=0;i<n;++i)
    {
        cin>>q>>w;
        if(q>w)
        {
            n1.push_back(node{q,w,i+1});
        }
        else if(q<w)
        {
            n2.push_back(node{q,w,i+1});
        }
    }
    sort(n1.begin(),n1.end(),cmp1);
    sort(n2.begin(),n2.end(),cmp2);
    long long sum1=0,sum2=0,lastnum=0;
    long long len=n1.size();
    for(long long i=0;i<len;++i)
    {
        for(vector<node>::iterator it = s1.begin();it!=s1.end();++it)
        {
            if(lastnum < (*it).u)
            {
                lastnum = (*it).v;
                q1.push_back((*it).bianhao);
                s1.erase(it);
                it=s1.begin();
                ++sum1;
            }
        }
        if(lastnum < n1[i].u)
        {
            lastnum=n1[i].v;
            q1.push_back(n1[i].bianhao);
            ++sum1;
        }
        else
        {
            s1.push_back(n1[i]);
        }
    }
    len = n2.size();
    lastnum=INF;
    for(long long i=0;i<len;++i)
    {
        for(vector<node>::iterator it = s2.begin();it!=s2.end();++it)
        {
            if(lastnum > (*it).u)
            {
                lastnum = (*it).v;
                q2.push_back((*it).bianhao);
                s2.erase(it);
                it=s2.begin();
                ++sum2;
            }
        }
        if(lastnum > n2[i].u)
        {
            lastnum = n2[i].v;
            q2.push_back(n2[i].bianhao);
            ++sum2;
        }
        else
        {
            s2.push_back(n2[i]);
        }
    }
    if(sum1>sum2)
    {
        cout<<sum1<<endl;
        for(long long i=0;i<q1.size();++i)
        {
            cout<<q1[i]<<" ";
        }
    }
    else
    {
        cout<<sum2<<endl;
        for(long long i=0;i<q2.size();++i)
        {
            cout<<q2[i]<<" ";
        }
    }
    return 0;
}
