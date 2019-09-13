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
    int x1,y1,x2,y2;
    string str;
    cin>>x1>>y1;
    cin>>str;
    cin>>x2>>y2;
    int d1,d2,d3;
    if(str[0]=='N')
    {
        d3=0;
    }
    else if(str[0]=='E')
    {
        d3=1;
    }
    else if(str[0]=='S')
    {
        d3=2;
    }
    else
    {
        d3=3;
    }
    if(x2>x1)
    {
        d1=1;
    }
    else if(x2<x1)
    {
        d1=3;
    }
    else
    {
        d1=-1;
    }
    if(y2>y1)
    {
        d2=0;
    }
    else if(y2<y1)
    {
        d2=2;
    }
    else
    {
        d2=-1;
    }
    vector<int> v1;
    queue<int> v2;
    while(x1!=x2 || y1!=y2)
    {
        if(d1==d3 && x1!=x2)
        {
            v1.push_back(2);
            v2.push(abs(x1-x2));
            x1=x2;
            continue;
        }
        if(d2==d3 && y1!=y2)
        {
            v1.push_back(2);
            v2.push(abs(y1-y2));
            y1=y2;
            continue;
        }
        v1.push_back(1);
        d3 = (d3+1)%4;
    }
    cout<<v1.size()<<endl;
    for(int i=0;i<v1.size();++i)
    {
        if(v1[i]==1)
        {
            cout<<"D"<<endl;
        }
        else if(v1[i]==2)
        {
            cout<<"A "<<v2.front()<<endl;
            v2.pop();
        }
    }
    return 0;
}
