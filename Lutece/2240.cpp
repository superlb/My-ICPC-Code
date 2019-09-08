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
//求解最长回文子串
const int MAXN=10000005;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(string str)
{
    int l=0,len=str.size();
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;++i)
    {
        Ma[l++]=str[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;++i)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
}
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int len;
    string str;
    cin>>len;
    cin>>str;
    Manacher(str);
    int ans=0;
    for(int i=0;i<len*2+2;++i)
    {
        if((Mp[i]-1)%2==0)
        {
            ans=max(ans,Mp[i]-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
