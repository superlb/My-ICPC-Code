#include<iostream>
using namespace std;
int main()
{
    int fish[99];
    int n;
    cin>>n;
    for(int j=0;j<n;++j)
    {
        int k;
        cin>>k;
        fish[j]=k;
        int h;
        h=0;
        int sum;
        sum=0;
        while(h<j)
        {
            if(fish[h]<fish[j])
            {
                ++sum;
            }
            ++h;
        }
        cout<<sum<<" ";
    }
    return 0;
}
