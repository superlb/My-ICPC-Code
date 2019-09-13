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
    long long n,tmp,add=0;
    stack<long long> s,q;
    bool is=true;
    string str;
    cin>>n;
    for(long long i=0;i<n;++i)
    {
        cin>>str;
        if(str[0]=='a')
        {
            add++;
        }
        else if(str[0]=='f')
        {
            cin>>tmp;
            s.push(tmp);
            q.push(add);
            add=0;
        }
        else if(str[0]=='e')
        {
            add*=s.top();
            s.pop();
            add+=q.top();
            q.pop();
        }
        if( add > ((1ll << 32ll) - 1ll) )
        {
            is=false;
            break;
        }
    }
    if(is)
    {
        cout<<add;
    }
    else
    {
        cout<<"OVERFLOW!!!";
    }
    return 0;
}
