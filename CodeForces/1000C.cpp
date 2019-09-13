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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,l,r;
    cin>>n;
    vector< pair<long long,long long> > a;
    vector<long long> v;
    for(int i=0;i<n;++i)
    {
        cin>>l>>r;
        a.push_back(make_pair(l,r));
        v.push_back(l);v.push_back(r+1);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    vector<long long> cnt(2*n);
    for(int i=0;i<n;++i)
    {
        int posl=lower_bound(v.begin(),v.end(),a[i].first) - v.begin();
        int posr=lower_bound(v.begin(),v.end(),a[i].second+1) - v.begin();
        ++cnt[posl];
        --cnt[posr];
    }
    vector<long long> ans(n+1);
    for(int i=1;i<2*n;++i)
        cnt[i]+=cnt[i-1];
    for(int i=1;i<2*n;++i)
    {
        ans[cnt[i-1]]+=v[i]-v[i-1];
    }
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
