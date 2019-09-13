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
    long long t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int len=str.length();
        bool is=true;
        for(int i=0;i<len;++i)
        {
            if(str[i] == 'A' || str[i] == 'H' ||str[i] == 'I' ||str[i] == 'M' ||str[i] == 'O' ||str[i] == 'T' || str[i] == 'U' ||str[i] == 'V' ||str[i] == 'W' ||str[i] == 'X' ||str[i] == 'Y')
            {
                continue;
            }
            else
            {
                is=false;
            }
        }
        if(is)
        {
            bool qqq=true;
            for(int i=0;i<len/2;++i)
            {
                if(str[i]!=str[len-i-1])
                {
                    qqq=false;
                    break;
                }
            }
            if(qqq)
            {
                cout<<"yes"<<endl;
            }
            else
            {
                cout<<"no"<<endl;
            }
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
