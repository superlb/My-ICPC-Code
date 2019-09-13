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
    int n;
    string str;
    int ans=0;
    cin>>n;
    cin>>str;
    while(str.find("xxx",0)!=-1)
    {
        int q=str.find("xxx",0);
        str.erase(q+2,1);
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
