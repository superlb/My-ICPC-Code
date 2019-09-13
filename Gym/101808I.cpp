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
const long long INF64 = 1ll << 59;
const unsigned long long HASHBASE=1222827239ull;
const long long MOD=1000000007ll;
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a;
        int ans=0;
        int minnum=INF;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            cin>>a;
            minnum=min(a,minnum);
            sum+=a;
        }
        if(n%2)
        {
            if(sum%2) cout<<"Yalalov"<<endl;
            else cout<<"Shin"<<endl;
        }
        else
        {
            if(minnum%2 || sum%2) cout<<"Yalalov"<<endl;
            else cout<<"Shin"<<endl;
        }
    }
    return 0;
}
