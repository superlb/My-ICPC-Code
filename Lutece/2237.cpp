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

///////////////////////////

////////
int a[200001];
int b[200001];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin>>n)
    {
        int sum=0;
        int tmp;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            b[a[i]]=i;
        }
        for(int i=1;i<=n;++i)
        {
            if(a[i]!=i)
            {
                tmp=a[b[i]];
                a[b[i]]=a[i];
                b[a[i]]=b[i];
                a[i]=tmp;
                b[i]=i;
                ++sum;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
