#include <bits/stdc++.h>
using namespace std;
long long getlen(long long a,long long b)
{
    long long d=1;
    b--;
    long long len=1;
    while(d<a && b>=4*len-1)
    {
        b-=4*len-1;
        len*=2;d++;
    }
    return a-d;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        if(n==2 && k==3)
        {
            cout<<"NO"<<endl;
            continue;
        }
        long long a=n,b=k;
        if(n<=60)
        {
            long long p=1;
            while(n--)
            {
                k-=p;
                p*=4;
            }
            if(k>0)
                cout<<"NO"<<endl;
            else
                cout<<"YES "<<getlen(a,b)<<endl;
        }
        else
            cout<<"YES "<<getlen(a,b)<<endl;
    }
    return 0;
}
