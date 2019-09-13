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
    long long x,y;
    cin>>x>>y;
    if(y==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(y==1)
    {
        if(x==0)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    long long q=x-(y-1);
    if(q<0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(q%2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}
