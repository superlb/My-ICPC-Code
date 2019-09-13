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
    cin>>n;
    int q=n%4;
    if(q==1)
    {
        cout<<0<<" A"<<endl;
    }
    else if(q==2)
    {
        cout<<1<<" B"<<endl;
    }
    else if(q==3)
    {
        cout<<2<<" A"<<endl;
    }
    else if(q==0)
    {
        cout<<1<<" A"<<endl;
    }
    return 0;
}
