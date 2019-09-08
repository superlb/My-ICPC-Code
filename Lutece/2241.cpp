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
void radix(int *str,int *a,int *b,int n,int m)
{
    static int count[1000050];
    memset(count,0,sizeof(count));
    for(int i=0;i<n;++i) ++count[str[a[i]]];
    for(int i=1;i<=m;++i) count[i]+=count[i-1];
    for(int i=n-1;i>=0;--i)b[--count[str[a[i]]]]=a[i];
}

void suffix_array(int *str,int *sa,int n,int m)
{
    static int rank[1000050],a[1000050],b[1000050];
    for(int i=0;i<n;++i)rank[i]=i;
    radix(str,rank,sa,n,m);
    rank[sa[0]]=0;
    for(int i=1;i<n;++i)
        rank[sa[i]]=rank[sa[i-1]]+(str[sa[i]]!=str[sa[i-1]]);
    for(int i=0;(1<<i) < n;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[j]=rank[j]+1;
            b[j]=j+(1<<i)>=n?0:rank[j+(1<<i)]+1;
            sa[j]=j;
        }
        radix(b,sa,rank,n,n);
        radix(a,rank,sa,n,n);
        rank[sa[0]]=0;
        for(int j=1;j<n;++j)
            rank[sa[j]]=rank[sa[j-1]] + (a[sa[j-1]] != a[sa[j]] || b[sa[j-1]] != b[sa[j]]);
    }
}
int work(string a,string b)
{
    static int s[1000050],sa[1000050],h[1000050],rank[1000050];
    string str;
    str = a + "#" + b;
    copy(str.begin(),str.end(),s);
    int len=str.length();
    suffix_array(s,sa,len,len+256);
    for(int i=0;i<len;++i)
        rank[sa[i]]=i;
    int curH=0;
    for(int i=0;i<len;++i)
    {
        curH = curH==0?0:curH-1;
        if(rank[i]!=0)
        {
            while(str[i+curH] == str[sa[rank[i]-1] + curH])
            {
                ++curH;
            }
        }
        else
        {
            curH=0;
        }
        h[rank[i]]=curH;
    }
    int ans=0,pos,alen=a.length();
    for(int i=1;i<len;++i)
    {
        if(h[i]>ans && (sa[i-1] <alen) != (sa[i] < alen))
        {
            ans=h[i];
            pos=sa[i];
        }
    }
    return ans;
}

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string str1,str2;
    cin>>str1>>str2;
    cout<<work(str1,str2)<<endl;
    return 0;
}
