#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,q;
    cin>>n>>m;
    int a[101];
    for(int i=0;i<n;++i)
        a[i] = 101;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>q;
            if(q!=-1)
                a[j]=min(a[j],q);
        }
    }
    int sum=0;
    for(int i=0;i<n;++i)
        sum += a[i];
    cout<<sum;
    return 0;
}
