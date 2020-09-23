//字符集大小，最小字符，最大点数
const int CHARSET=26,BASE='a',MAX_NODE=100000;
struct Trie
{
    int tot,root,child[MAX_NODE][CHARSET];
    bool flag[MAX_NODE];
    Trie()
    {
        memset(child[1],0,sizeof(child[1]));
        flag[1]=false;
        root=tot=1;
    }
    void insert(string str)
    {
        int *cur = &root;
        int len=str.length();
        for(int i=0;i<len;++i)
        {
            cur=&child[*cur][str[i]-BASE];
            if(*cur==0)
            {
                *cur=++tot;
                memset(child[tot],0,sizeof(child[tot]));
                flag[tot]=false;
            }
        }
        flag[*cur]=true;
    }
    bool query(string str)
    {
        int *cur = &root;
        int len=str.length();
        for(int i=0;i<len && *cur;++i)
        {
            cur=&child[*cur][str[i]-BASE];
        }
        return (*cur && flag[*cur]);
    }
};

//c++风格重写

struct Trie
{
    int tot,root;
    vector< vector<int> > child;
    vector<bool> flag;
};

