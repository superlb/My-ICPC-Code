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
long long n,m,a;
long long sum=0;
vector<long long> v;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    v.push_back(0);
    for(int i=0;i<n;++i)
    {
        cin>>a;
        sum+=a;
        v.push_back(sum);
    }
    for(int i=0;i<m;++i)
    {
        cin>>a;
        auto it = lower_bound(v.begin(),v.end(),a);
        cout<<(it-v.begin())<<" "<<(a-(*(it-1)))<<endl;
    }
    return 0;
}
