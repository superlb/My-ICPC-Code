#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n,k;
string str;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>k>>str;
        int dp[1000][26];
        fill(dp[0],dp[0]+1000*26,100000000);
        int block=str.length()/k;
        int a[1000][26]={0};
        int sum=0;
        int w[1000]={0};
        for(int j=0;j<block;++j)
        {
            sum=0;
            for(int q=0;q<k;++q)
            {
                if(a[j][str[j*k+q]-97]==0)
                {
                    ++a[j][str[j*k+q]-97];
                    ++sum;
                }
            }
            w[j]=sum;
        }
        for(int j=0;j<26;++j)
        {
            if(a[0][j])
            {
                dp[0][j]=w[0];
            }
        }
        for(int j=1;j<block;++j)
        {
            for(int l=0;l<26;++l)
            {
                if(a[j-1][l]==1)
                {
                    if(a[j][l]==1)
                    {
                        for(int q=0;q<26;++q)
                        {
                            if(a[j][q]==1 && l!=q)
                            {
                                dp[j][q]=min(dp[j-1][l]+w[j]-1,dp[j][q]);
                            }
                        }
                        if(w[j]==1)
                        {
                            dp[j][l]=min(dp[j-1][l],dp[j][l]);
                        }
                    }
                    else
                    {
                        for(int q=0;q<26;++q)
                        {
                            if(a[j][q]==1)
                            {
                                dp[j][q]=min(dp[j-1][l]+w[j],dp[j][q]);
                            }
                        }
                    }
                }

            }
        }
        int minnum=1000000000;
        for(int j=0;j<26;++j)
        {
            if(dp[block-1][j]<minnum)
            {
                minnum=dp[block-1][j];
            }
        }
        cout<<minnum<<endl;
    }
    return 0;
}
