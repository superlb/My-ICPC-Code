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
int a[1100][1100];
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        int u,v;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&u,&v);
            a[u][v]=1;
        }
        if(a[1][n])
        {
            printf("Jorah Mormont\n");
        }
        else
        {
            printf("Khal Drogo\n");
        }
    }
    return 0;
}
