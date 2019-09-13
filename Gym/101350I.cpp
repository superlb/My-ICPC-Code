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
const int MAXN=1010;
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
    long long t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int len=str.length();
        int ans=0;
        for(int i=0;i<len;++i)
        {
            if(str[i] == 'A' || str[i] == 'H' ||str[i] == 'I' ||str[i] == 'M' ||str[i] == 'O' ||str[i] == 'T' || str[i] == 'U' ||str[i] == 'V' ||str[i] == 'W' ||str[i] == 'X' || str[i] == 'Y')
            {
                int leng=1;
                while(str[i+leng] == 'A' || str[i+leng] == 'H' ||str[i+leng] == 'I' ||str[i+leng] == 'M' ||str[i+leng] == 'O' ||str[i+leng] == 'T' || str[i+leng] == 'U' ||str[i+leng] == 'V' ||str[i+leng] == 'W' ||str[i+leng] == 'X' || str[i+leng] == 'Y')
                {
                    ++leng;
                }
                string str2=str.substr(i,leng);
                memset(Ma,0,sizeof(Ma));
                memset(Mp,0,sizeof(Mp));
                Manacher(str2);
                for(int j=0;j<2*leng+1;++j)
                {
                    ans=max(ans,Mp[j]-1);
                }
                i+=leng-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
