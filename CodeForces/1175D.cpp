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
const long long INF64 = 3e18;

///////////////////////////
long long a[300002];
vector<long long> s;
long long n,k,sum=0;
////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    for(long long i=0;i<n;++i)
    {
        cin>>a[i];
    }
    s.push_back(a[n-1]);
    for(long long i=n-2;i>=0;--i)
    {
        s.push_back(s[n-i-2]+a[i]);
    }
    sum+=s[n-1];
    sort(s.begin(),--s.end());
    for(long long i=0;i<k-1;++i)
    {
        sum+=s[n-2-i];
    }
    cout<<sum;
    return 0;
}
