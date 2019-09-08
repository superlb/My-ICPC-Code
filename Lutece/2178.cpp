#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
long long strtoint(string strs)
{
    long long len=strs.length();
    long long ans=1;
    long long sum=0;
    for(long long i=len-1;i>=0;--i)
    {
        if(strs[i] == '1')
            sum+=ans;
        ans = ans << 1;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long t;
    cin>>t;
    for(long long nowt=1;nowt<=t;++nowt)
    {
        long long n,a[16],s[1 << 16],f[1 << 16];
        string str;
        memset(f,0,sizeof(f));
        cin>>n;
        cin>>str;
        fill(s,s+(1<<16),strtoint(str));
        for(long long i=0;i<n;++i)
        {
            cin>>str;
            a[i]=strtoint(str);
        }
        for(long long i=1;i<(1<<n);++i)
        {
            for(long long j=0;j<n;++j)
            {
                if(i & ( 1 << (n - j - 1) ) )
                {
                    s[i]=s[i] | a[j];
                }
            }

        }
        f[0]=1;
        for(long long i=0;i < (1<<n);++i)
        {
            if(!f[i])
            {
                continue;
            }
            for(long long j=0;j<n;++j)
            {
                if( ( s[i] & (1 << j) ) && ( ( i & (1 << j) ) == 0 ) )
                {
                    f[i | (1 << j)] += f[i];
                }
            }
        }
        cout<<"Case "<<nowt<<": "<<f[(1<<n) - 1]<<endl;
    }
    return 0;
}
