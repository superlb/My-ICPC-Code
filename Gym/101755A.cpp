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
    long long s,g;
    cin>>s>>g;
    if(s%g)
    {
        cout<<-1<<endl;
        return 0;
    }
    long long a=s/g;
    if(a==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        cout<<g<<" "<<s-g<<endl;
    }
    return 0;
}
