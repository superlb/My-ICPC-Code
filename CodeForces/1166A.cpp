#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    string str;
    int a[26]={0};
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>str;
        ++a[str[0]-97];
    }
    for(int i=0;i<26;++i)
    {
        if(a[i]%2)
        {
            int q=a[i]/2;
            sum+=q*(q-1)/2;
            ++q;
            sum+=q*(q-1)/2;
        }
        else
        {
            int q=a[i]/2;
            sum+=q*(q-1);
        }
    }
    cout<<sum;
    return 0;
}
