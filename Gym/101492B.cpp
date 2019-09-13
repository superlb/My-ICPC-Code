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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    if(n%4==1 || n%4==2)
    {
        cout<<-1<<endl;
    }
    else
    {
        int q=n/4;
        int r=n/2;
        for(int i=0;i<q;++i)
        {
            cout<<"-";
        }
        for(int i=0;i<n-r;++i)
        {
            cout<<"+";
        }
        for(int i=0;i<r-q;++i)
        {
            cout<<"-";
        }
        cout<<endl;
    }
    return 0;
}
