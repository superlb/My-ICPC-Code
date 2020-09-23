struct ac
{
    int ch[300000][128];
    int val[300000];
    int f[300000];
    int last[300000];
    int cnt[300000];
    int sz;
    ac()
    {
        sz=1;memset(ch[0],0,sizeof(ch[0]));
        memset(cnt,0,sizeof(cnt));
    }
    void insert(string str,int v)
    {
        int u=0,len=str.length();
        for(int i=0;i<len;++i)
        {
            int c=str[i];
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
		val[u]=v;
    }
    void find(string str)
    {
        int len=str.length();
        int j=0;
        for(int i=0;i<len;++i)
        {
            int c=str[i];
            j=ch[j][c];
            if(val[j])
            {
                int linshi=j;
                while(linshi)
                {
                    ++cnt[val[linshi]];
                    linshi=last[linshi];
                }
            }
            else if(last[j])
            {
                int linshi=last[j];
                while(linshi)
                {
                    ++cnt[val[linshi]];
                    linshi=last[linshi];
                }
            }
        }
    }
    void build()
    {
        queue<int> q;
        f[0]=0;
        for(int c=0;c<128;++c)
        {
            int u=ch[0][c];
            if(u)
            {
                f[u]=0;
                q.push(u);
                last[u]=0;
            }
        }
        while(!q.empty())
        {
            int r=q.front();q.pop();
            for(int c=0;c<128;++c)
            {
                int u=ch[r][c];
                if(!u)
                {
                    ch[r][c]=ch[f[r]][c];
                    continue;
                }
                q.push(u);
                int v=f[r];
                while(v && !ch[v][c])v=f[v];
                f[u]=ch[v][c];
                last[u]=val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
};
