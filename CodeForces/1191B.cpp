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
    string str1,str2,str3;
    string str[27]={"1m","2m","3m","4m","5m","6m","7m","8m","9m","1p","2p","3p","4p","5p","6p","7p","8p","9p","1s","2s","3s","4s","5s","6s","7s","8s","9s"};
    cin>>str1>>str2>>str3;
    int a[3];
    int q[27];
    for(int i=0;i<9;++i)
    {
        q[i]=1;
    }
    for(int i=9;i<18;++i)
    {
        q[i]=2;
    }
    for(int i=18;i<27;++i)
    {
        q[i]=3;
    }
    for(int i=0;i<27;++i)
    {
        if(str1==str[i])
            a[0]=i;
    }
    for(int i=0;i<27;++i)
    {
        if(str2==str[i])
            a[1]=i;
    }
    for(int i=0;i<27;++i)
    {
        if(str3==str[i])
            a[2]=i;
    }
    sort(a,a+3);
    if(a[0]==a[1] && a[1]==a[2])
    {
        cout<<0<<endl;
        return 0;
    }
    if(a[1] - a[0] == 0 || a[2] - a[1] == 0)
    {

        cout<<1<<endl;
        return 0;
    }
    if(a[1] - a[0] == 1 && a[2] - a[1] == 1)
    {
        if(q[a[1]] == q[a[0]] && q[a[2]] == q[a[1]])
        {
            cout<<0<<endl;
            return 0;
        }
        else
        {
            cout<<1<<endl;
            return 0;
        }
    }
    if(a[1] - a[0] == 1 && q[a[1]] == q[a[0]])
    {
        cout<<1<<endl;
        return 0;
    }
    if(a[2] - a[1] == 1 && q[a[1]] == q[a[2]])
    {
        cout<<1<<endl;
        return 0;
    }
    if(a[1] - a[0] == 2 && q[a[1]] == q[a[0]])
    {
        cout<<1<<endl;
        return 0;
    }
    if(a[2] - a[1] == 2 && q[a[1]] == q[a[2]])
    {
        cout<<1<<endl;
        return 0;
    }
    cout<<2<<endl;
    return 0;
}
