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
const long long MOD=1000000007ll;
/////////////////////////
const int MAXN=11000010;
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
    string str;
    cin>>str;
    Manacher(str);
    int ans=0;
    int len=2*str.size()+2;
    for(int i=0;i<len;++i)
    {
        ans=max(ans,Mp[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}
