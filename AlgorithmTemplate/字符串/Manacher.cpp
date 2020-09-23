//求解最长回文子串
const int MAXN=110010;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(string str)
{
    int l=0,len=str.size();
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;++i)
    {
        Ma[l++]=str[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;++i)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
}
int main()
{
    string str;
    cin>>str;
    Manacher(str);
    int ans=0;
    for(int i=0;i<2*str.size()+2;++i)
    {
        ans=max(ans,Mp[i]-1);
    }
    cout<<str;
}
