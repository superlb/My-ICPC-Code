#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    scanf("%d",&a);
    if(a==1)
        printf("Wed.Strong");
    else
    {
        a /=2;
        for(int i=0;i<a;++i)
            printf("Wed.Strong");
    }
    return 0;
}
