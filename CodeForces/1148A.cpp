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

////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<c*2+min(a,b)*2+((abs(a-b)>0)?1:0);
    return 0;
}
