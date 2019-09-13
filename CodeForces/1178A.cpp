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
int a[110];
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ans+=a[i];
    }
    vector<int> v;
    v.push_back(1);
    int sum=a[1];
    for(int i=2;i<=n;++i)
    {
        if(a[1]>=2*a[i])
        {
            v.push_back(i);
            sum+=a[i];
        }
    }
    if(sum>ans/2)
    {
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();++i)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}
