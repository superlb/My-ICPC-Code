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
    int n;
    string str;
    cin>>n>>str;
    int sum=0;
    for(int i=1;i<=n/2;++i)
    {
        bool is=true;
        for(int j=0;j<i;++j)
        {
            if(str[j]!=str[i+j])
            {
                is=false;
                break;
            }
        }
        if(is)
        {
            sum=i;
        }
    }
    sum = sum + n - 2*sum + ((sum>0)?1:0) ;
    cout<<sum<<endl;
    return 0;
}
