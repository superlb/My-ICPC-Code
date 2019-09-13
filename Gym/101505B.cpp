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
    int n;
    while(cin>>n)
    {
        string str;
        set<long long> s;
        for(int i=0;i<n;++i)
        {
            cin>>str;
            long long a[10]={0,0,0,0,0,0,0,0,0,0};
            for(int j=0;j<str.length();++j)
            {
                ++a[str[j]-'0'];
            }
            long long q=1;
            long long sum=0;
            for(int j=1;j<10;++j)
            {
                if(a[j])
                {
                    sum+=q;
                }
                q*=10;
            }
            s.insert(sum);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
