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
const unsigned long long HASHBASE=1222827239ull;
const long long MODNUM=1000000007ll;
/////////////////////////
//s
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int h,w,n,qwe;
    while(cin>>h>>w>>n)
    {
        int len=sqrt(n);
        vector<int> block(len+1,w);
        vector<int> cnt(len+1,0);
        vector<int> hh(n+1,w);
        for(int i=0;i<n;++i)
        {
            cin>>qwe;
            bool update=false;
            for(int j=0;j<=len+1;++j)
            {
                if(update) break;
                if(j==len+1)
                {
                    cout<<-1<<endl;
                    break;
                }
                if(qwe <= block[j])
                {
                    for(int k=j*len+1;k<=h;++k)
                    {
                        if(qwe<=hh[k])
                        {
                            cout<<k<<endl;
                            update=true;
                            ++cnt[j];
                            hh[k]=hh[k]-qwe;
                            break;
                        }
                    }
                    if(cnt[j]>=len)
                    {
                        block[j]=0;
                        for(int k=j*len+1;k<=(j+1)*len;++k)
                        {
                            block[j]=max(block[j],hh[k]);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
