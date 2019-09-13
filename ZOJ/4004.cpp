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
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m,a;
        cin>>n>>m;
        vector<long long> v;
        for(int i=0;i<n;++i)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        long long sum=0;
        for(int i=0;i<m;++i)
        {
            sum+=v[i]*v[2*m-i-1];
        }
        cout<<sum<<endl;
    }
    return 0;
}
