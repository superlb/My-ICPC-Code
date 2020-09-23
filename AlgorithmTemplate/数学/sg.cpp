int f[MAXN],sg[MAXN];
bool vis[MAXN];
void getSG(int n)
{
    sort(f+1,f+1+n);
    memset(sg,0,sizeof(sg));
    for (int i=1; i<=n; i++)
    {
        memset(vis,0,sizeof(vis));
        for (int j=1; f[j]<=i; j++)//f排序是为了让每一种取法都循环到
            vis[sg[i-f[j]]]=1;
        for (int j=0; j<=n; j++)
        {
            if (vis[j]==0)
            {
                sg[i]=j; break;
            }
        }
    }
}
