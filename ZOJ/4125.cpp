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
    //ios::sync_with_stdio(false); cin.tie(0);
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;++i)
        {
            if(n==1 || n==0) break;
            if(n%2)
            {
                n=(n+1)/2;
            }
            else
            {
                n=n/2;
            }
        }
        printf("%d\n",n);
    }
    return 0;
}
