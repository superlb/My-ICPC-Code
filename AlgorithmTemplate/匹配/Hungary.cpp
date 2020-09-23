const int MAXN=555;
const int n=100;
vector<int> g[MAXN];
int from[MAXN],tot;
bool use[MAXN];
bool match(int x)
{
    for(int i=0;i<g[x].size();++i)
    {
        if(!use[g[x][i]])
        {
            use[g[x][i]]=true;
            if(from[g[x][i]] == -1 || match(from[g[x][i]]))
            {
                from[g[x][i]]=x;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    tot=0;
    memset(from,255,sizeof(from))
    for(int i=1;i<=n;++i)
    {
        memset(use,0,sizeof(use));
        if(match(i))
            ++tot;
    }
    return tot;
}
