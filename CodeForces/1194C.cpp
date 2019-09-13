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
const long long MODNUM=1000000007ll;
/////////////////////////
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    string str1,str2,str3;
    int a[26],b[26],c[26];
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        bool is=true;
        cin>>str1>>str2>>str3;
        int len=str1.length();
        for(int i=0;i<len;++i)
        {
            ++a[str1[i]-'a'];
        }
        len=str2.length();
        for(int i=0;i<len;++i)
        {
            ++b[str2[i]-'a'];
        }
        len=str3.length();
        for(int i=0;i<len;++i)
        {
            ++c[str3[i]-'a'];
        }
        for(int i=0;i<26;++i)
        {
            if(a[i]>b[i] || a[i]+c[i]<b[i])
            {
                is=false;
            }
        }
        for(int i=0,j=0;i<str1.length();)
        {
            if(j==str2.length())
            {
                is=false;
                break;
            }
            if(str1[i]==str2[j])
            {
                ++i;++j;
            }
            else
            {
                ++j;
            }
        }
        if(is)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
