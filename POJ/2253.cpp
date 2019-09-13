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
const long long INF64 = 5e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
int x[202],y[202];
int n;
int dismap[202][202];
int tot=1;
/////////////////////////
int main()
{
    //ios::sync_with_stdio(false); cin.tie(0);
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=1;i<=n;++i)
        {
            cin>>x[i]>>y[i];
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dismap[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                if(i==j)dismap[i][j]=INF;
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                for(int k=1;k<=n;++k)
                {
                    dismap[j][k]=min(dismap[j][k],max(dismap[j][i],dismap[i][k]));
                }
            }
        }
        printf("Scenario #%d\n",tot++);
        printf("Frog Distance = %.3f\n",sqrt(1.0*dismap[1][2]));
        printf("\n");
    }
    return 0;
}
