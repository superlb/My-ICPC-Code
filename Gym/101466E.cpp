#include <bits/stdc++.h>
using namespace std;
void preKMP(string x,int m,int kmpNext[])
{
    int i,j;
    j=kmpNext[0]=-1;
    i=0;
    while(i<m)
    {
        while(j!=-1 && x[i]!=x[j]) j=kmpNext[j];
        if(x[++i]==x[++j])kmpNext[i]=kmpNext[j];
        else kmpNext[i]=j;
    }
}
int nexts[200010];
int KMP_Count(string x,string y)
{
    int i=0,j=0;
    int ans=0;
    int m=x.length(),n=y.length();
    preKMP(x,m,nexts);
    while(i<n)
    {
        while(j!=-1 && y[i]!=x[j]) j=nexts[j];
        i++;j++;
        if(j>=m)
        {
            ans++;
            j=nexts[j];
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string str1,str2;
    int n;
    getline(cin,str1);
    getline(cin,str2);
    cin>>n;
    int l=0;int r=str2.length();
    while(l+1!=r)
    {
        int m=(l+r)/2;
        string str3=str2.substr(0,m);
        int q=KMP_Count(str3,str1);
        if(q>=n)
        {
            l=m;
        }
        else
        {
            r=m;
        }
    }
    string str3=str2.substr(0,r);
    int q=KMP_Count(str3,str1);
    if(q>=n)
    {
        if(str3=="")
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<str3<<endl;
        return 0;
    }
    str3=str2.substr(0,l);
    q=KMP_Count(str3,str1);
    if(q>=n)
    {
        if(str3=="")
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        cout<<str3<<endl;
        return 0;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
