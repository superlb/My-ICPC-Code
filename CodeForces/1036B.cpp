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
using namespace std;

///////////////////////////

////////

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long q,n,m,k;
    cin>>q;
    for(long long i=0;i<q;++i)
    {
        cin>>n>>m>>k;
        if(n<m) swap(n,m);
        if( n % 2 != m % 2 )
        {
            k-=1;n-=1;
        }
        else if(n % 2 != k % 2)
        {
            k-=2;
            n-=1;
            m-=1;
        }
        cout<<((k<n)?(-1):(k))<<endl;
    }
    return 0;
}
