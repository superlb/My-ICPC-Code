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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;

/////////////////////////

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    if(z==0)
    {
        if(x>y)
        {
            cout<<"+"<<endl;
        }
        else if(x<y)
        {
            cout<<"-"<<endl;
        }
        else if(x==y)
        {
            cout<<"0"<<endl;
        }
        return 0;
    }
    if(z>=abs(x-y))
    {
        cout<<"?"<<endl;
        return 0;
    }
    if(x>y+z)
    {
        cout<<"+"<<endl;
        return 0;
    }
    else
    {
        cout<<"-"<<endl;
        return 0;
    }
    return 0;
}
