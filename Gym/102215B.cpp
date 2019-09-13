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
    string str1,str2,str3="",str4="";
    cin>>str1>>str2;
    int len=str1.length();
    int ans1=0,ans2=0;
    bool is=false;
    for(int i=0;i<len;++i)
    {
        if(str1[i]=='#' && str2[i]=='#')
        {
            is=true;
        }
        if(str1[i]=='#')
            ++ans1;
        if(str2[i]=='#')
            ++ans2;
    }
    if(ans1!=0 && ans2==0)
        is=true;
    if(ans2!=0 && ans1==0)
        is=true;
    if(is)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<len;++i)
        {
            if(str1[i]=='#' && str2[i]=='.')
            {
                str3.append(1,'#');
                str4.append(1,'.');
            }
        }
        for(int i=0;i<len;++i)
        {
            if(str1[i]=='#' && str2[i]=='#')
            {
                str3.append(1,'#');
                str4.append(1,'#');
            }
        }
        for(int i=0;i<len;++i)
        {
            if(str1[i]=='.' && str2[i]=='#')
            {
                str3.append(1,'.');
                str4.append(1,'#');
            }
        }
        for(int i=0;i<len;++i)
        {
            if(str1[i]=='.' && str2[i]=='.')
            {
                str3.append(1,'.');
                str4.append(1,'.');
            }
        }
        cout<<str3<<endl;
        cout<<str4<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
