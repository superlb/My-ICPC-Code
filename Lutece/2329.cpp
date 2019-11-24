#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    int a[5000];
    cin>>n>>x>>y;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int is = 1;
    int tot = 0;
    int res = 0;
    for(int i=0;i<n;++i)
    {
        res += (a[i]+y-1)/y;
    }
    while(is)
    {
        is=0;
        ++tot;
        int sum = tot;
        for(int i=0;i<n;++i)
        {
            if(a[i])
            {
                is = 1;
                a[i] = a[i]-x>0?a[i]-x:0;
                sum += (a[i]+y-1)/y;
            }
        }
        res = min(res,sum);
    }
    cout<<res<<endl;
    return 0;
}
