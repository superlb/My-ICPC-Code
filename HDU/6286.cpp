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
    long long a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        long long d1=b/2ll-(a-1ll)/2ll;;
        long long d2=b/1009ll-(a-1ll)/1009ll;
        long long d3=b/2018ll-(a-1ll)/2018ll;
        long long d4=d/2ll-(c-1ll)/2ll;;
        long long d5=d/1009ll-(c-1ll)/1009ll;
        long long d6=d/2018ll-(c-1ll)/2018ll;
        cout<<(d4-d6)*(d2-d3)+(d5-d6)*(d1-d3)+d6*(b-a+1ll)+d3*(d-c+1ll)-d3*d6<<endl;
    }
    return 0;
}
