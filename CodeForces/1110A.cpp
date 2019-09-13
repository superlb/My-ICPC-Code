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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int b,k,sum=0,a;
    cin>>b>>k;
    for(int i=0;i<k;++i)
    {
        cin>>a;
        sum+=a;
    }
    if(b%2)
    {
        if(sum%2)
        {
            cout<<"odd";
        }
        else
        {
            cout<<"even";
        }
    }
    else
    {
        if(a%2)
        {
            cout<<"odd";
        }
        else
        {
            cout<<"even";
        }
    }
    return 0;
}
