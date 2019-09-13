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
    string str1,str2;
    while(cin>>str1>>str2)
    {
        string str3="c",str4="c";
        str3.append(str1);str3.append(1,'c');
        str4.append(str2);str4.append(1,'c');
        int len1=str3.length();
        int len2=str4.length();
        if(len1%2!=len2%2)
        {
            cout<<"No"<<endl;
            continue;
        }
        vector<int> v1,v2;
        for(int i=0;i<len1;++i)
        {
            if(str3[i]=='c')
                v1.push_back(i);
        }
        for(int i=0;i<len2;++i)
        {
            if(str4[i]=='c')
                v2.push_back(i);
        }
        if(v1.size()!=v2.size())
        {
            cout<<"No"<<endl;
            continue;
        }
        int len3=v1.size();
        for(int i=0;i<len3;++i)
        {
            if(i==len3-1)
            {
                cout<<"Yes"<<endl;
                break;
            }
            int d1=0,d2=0;
            for(int j=v1[i]+1;j<v1[i+1];++j)
            {
                if(str3[j]=='a')
                    ++d1;
                else if(str3[j]=='b')
                    ++d2;
            }
            int d3=0,d4=0;
            for(int j=v2[i]+1;j<v2[i+1];++j)
            {
                if(str4[j]=='a')
                    ++d3;
                else if(str4[j]=='b')
                    ++d4;
            }
            if(d1%2!=d3%2 || d2%2!=d4%2)
            {
                cout<<"No"<<endl;
                break;
            }
        }
    }
    return 0;
}
