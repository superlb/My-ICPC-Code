//AC自动机
//求目标串中出现了几个模式串
struct Trie
{
    int next[500010][26],fail[500010],end[500010];
    int root,L;
    int newnode()
    {
        for(int i=0;i<26;++i)
            next[L][i]=-1;
        end[L++]=0;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(string str)
    {
        int len=str.size();
        int now=root;
        for(int i=0;i<len;++i)
        {
            if(next[now][str[i]-'a'] == -1)
                next[now][str[i]-'a'] = newnode();
            now = next[now][str[i]-'a'];
        }
        end[now]++;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for(int i=0;i<26;++i)
        {
            if(next[root][i]==-1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty())
        {
            int now=Q.front();Q.pop();
            for(int i=0;i<26;++i)
            {
                if(next[now][i]==-1)
                {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    int query(string str)
    {
        int len=str.size();
        int now=root;
        int res=0;
        for(int i=0;i<len;++i)
        {
            now=next[now][str[i]-'a'];
            int temp=now;
            while(temp!=root)
            {
                res += end[temp];
                end[temp] = 0;
                temp = fail[temp];
            }
        }
        return res;
    }
};
Trie ac;
int main()
{
    int n;
    string tmp;
    cin>>n;
    ac.init();
    for(int i=0;i<n;++i)
    {
        cin>>tmp;
        ac.insert(tmp);
    }
    ac.build();
    cin>>tmp;
    cout<<ac.query(tmp)<<endl;
}
