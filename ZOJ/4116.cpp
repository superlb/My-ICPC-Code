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
const long long MOD=1000000007ll;
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,k,n,m,u,v,s;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>k;
        cin>>str;
        cin>>n>>m;
        for(int i=0;i<m;++i)
            cin>>u>>v;
        s=(m-n+1)%k;
        if(str[s]=='1')
            cout<<2<<endl;
        else
            cout<<1<<endl;
    }
    return 0;
}
