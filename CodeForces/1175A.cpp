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
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;

///////////////////////////

////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long t,n,k,sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum=0;
        while(n!=0)
        {
            sum+=n%k;
            n/=k;
            sum++;
        }
        cout<<sum-1<<endl;
    }
    return 0;
}
