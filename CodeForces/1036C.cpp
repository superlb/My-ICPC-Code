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
const int INF = 0x3f3f3f3f;

///////////////////////////
vector<long long> res;
void dfs(int pos,int cnt,long long now)
{
    if(pos==18)
    {
        res.push_back(now);
        return;
    }
    dfs(pos+1,cnt,now*10);
    if(cnt<3)
    {
        for(int i=1;i<=9;++i)
        {
            dfs(pos+1,cnt+1,now*10+i);
        }
    }
}
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    dfs(0,0,0);
    res.push_back(1000000000000000000);
    sort(res.begin(),res.end());
    long long t,l,r;
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<upper_bound(res.begin(),res.end(),r)-lower_bound(res.begin(),res.end(),l)<<endl;
    }
    return 0;
}
