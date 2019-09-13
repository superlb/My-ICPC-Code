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

/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    string str1,str2;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        int len=str1.length();
        if(str1[len/2]!=str2[len/2])
        {
            cout<<-1<<endl;
            continue;
        }
        bool is=true;
        int ans=0;
        for(int i=0;i<len/2;++i)
        {
            if(str1[i]==str2[i] && str1[len-1-i]==str2[len-1-i])
            {
                if(ans%2 && str1[i]!=str1[len-1-i])
                {
                    ++ans;
                }
            }
            else if(str1[i]==str2[len-1-i] && str1[len-1-i]==str2[i])
            {
                if(ans%2==0 && str1[i]!=str1[len-1-i])
                {
                    ++ans;
                }
            }
            else
            {
                is=false;
                break;
            }
        }
        if(is)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}
