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
    string str1,str2;
    cin>>str1>>str2;
    unsigned long long str1len=str1.size(),str2len=str2.size(),ah=0,bh=0,t=1;
    for(unsigned long long i=0;i<str2len;++i)
    {
        t*=HASHBASE;
        ah=ah*HASHBASE+str1[i];
        bh=bh*HASHBASE+str2[i];
    }
    for(unsigned long long i=0;i+str2len<=str1len;++i)
    {
        if(ah==bh)
        {
            cout<<i+1<<" ";
        }
        if(i+str2len<str1len)
        {
            ah=ah*HASHBASE+str1[i+str2len]-str1[i]*t;
        }
    }
    return 0;
}
