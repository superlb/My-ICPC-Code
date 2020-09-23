const int MAXN=200005;
void work(string a,string b)
{
    static int s[MAXN],sa[MAXN],h[MAXN],rank[MAXN];
    string str;
    str = a + "#" + b;
    copy(str.begin(),str.end(),s);
    int len=str.length();
    suffix_array(s,sa,len,len+256);
    for(int i=0;i<len;++i)
        rank[sa[i]]=i;
    int curH=0;
    for(int i=0;i<len;++i)
    {
        curH = curH==0?0:curH-1;
        if(rank[i]!=0)
        {
            while(str[i+curH] == str[sa[rank[i]-1] + curH])
            {
                ++curH;
            }
        }
        else
        {
            curH=0;
        }
        h[rank[i]]=curH;
    }
    int ans=0,pos,alen=a.length();
    for(int i=1;i<len;++i)
    {
        if(h[i]>ans && (sa[i-1] <alen) != (sa[i] < alen))
        {
            ans=h[i];
            pos=sa[i];
        }
    }
    if(ans==0)
    {
        cout<<endl;
    }
    else
    {
        cout<<str.substr(pos,ans)<<endl;
    }
}
