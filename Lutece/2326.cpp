#include <bits/stdc++.h>
using namespace std;
int res[110][11111];
int main()
{
    int n;
    int k[10010],b[10010];
    int sum[10010];
    memset(sum,0,sizeof(sum));
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>k[i]>>b[i];
        for(int x=0;x<101;++x)
            ++res[x][x*k[i]+b[i]];
    }
    for(int i=0;i<110;++i)
    {
        for(int j=0;j<11111;++j)
        {
            ++sum[res[i][j]];
        }
    }
    for(int i=2;i<=n;++i)
        cout<<sum[i]<<" ";
    return 0;
}
