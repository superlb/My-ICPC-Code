#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <set>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
const long long MODNUM=1000000007ll;
/////////////////////////
struct Splay//存储规则：小左大右，重复节点记录
{
    #define root e[0].ch[1]   //该树的根节点
    struct node
    {
        long long v,father;//节点值，父级节点
        long long ch[2];//左孩子=0，右孩子=1
        long long sum;//自己+自己下级有多少节点。在根节点为1。
        long long recy;//记录自己被重复了几次
    };
    node e[400010];//Splay树主体
    long long n,points;//使用存储数,元素数
    void update(long long x)//更新当前节点的sum值
    {
        e[x].sum=e[e[x].ch[0]].sum+e[e[x].ch[1]].sum+e[x].recy;
    }
    long long identify(long long x)//获取父子关系
    {
        return e[e[x].father].ch[0]==x?0:1;
    }
    void connect(long long x,long long f,long long son)//连接函数。用法：connect(son,father,左儿子（0）或右儿子（1）)
    {
        e[x].father=f;e[f].ch[son]=x;
    }//作用：将x连接在f的下方。连接方向由son的值决定。
    void rotate(long long x)
    {
        long long y=e[x].father;
        long long mroot=e[y].father;
        long long mrootson=identify(y);
        long long yson=identify(x);
        long long B=e[x].ch[yson^1];
        connect(B,y,yson);connect(y,x,(yson^1));connect(x,mroot,mrootson);
        update(y);update(x);
    }
    void splay(long long at,long long to)
    {
        to=e[to].father;
        while(e[at].father!=to)
        {
            long long up=e[at].father;
            if(e[up].father==to) rotate(at);
            else if(identify(up)==identify(at))
            {
                rotate(up);rotate(at);
            }
            else
            {
                rotate(at);rotate(at);
            }
        }
    }
    long long crepoint(long long v,long long father)
    {
        n++;
        e[n].v=v;
        e[n].father=father;
        e[n].sum=e[n].recy=1;
        return n;
    }
    void destroy(long long x)
    {
        e[x].v=e[x].ch[0]=e[x].ch[1]=e[x].sum=e[x].father=e[x].recy=0;
        if(x==n) n--;
    }
    long long find(long long v)
    {
        long long now=root;
        while(true)
        {
            if(e[now].v==v)
            {
                splay(now,root);
                return now;
            }
            long long next=v<e[now].v?0:1;
            if(!e[now].ch[next]) return 0;
            now=e[now].ch[next];
        }
    }
    long long build(long long v)//内部调用的插入函数，没有splay
    {
        points++;
        if(n==0)//特判无点状态
        {
            root=1;
            crepoint(v,0);
        }
        else
        {
            long long now=root;
            while(true)//向下找到一个空节点
            {
                e[now].sum++;//自己的下级肯定增加了一个节点
                if(v==e[now].v)
                {
                    e[now].recy++;
                    return now;
                }
                long long next=v<e[now].v?0:1;
                if(!e[now].ch[next])
                {
                    crepoint(v,now);
                    e[now].ch[next]=n;
                    return n;
                }
                now=e[now].ch[next];
            }
        }
        return 0;
    }
    void push(long long v)//插入节点
    {
        long long add=build(v);
        splay(add,root);
    }
    void pop(long long v)//删除节点
    {
        long long deal=find(v);
        if(!deal) return;
        points--;
        if(e[deal].recy>1)
        {
            e[deal].recy--;
            e[deal].sum--;
            return;
        }
        if(!e[deal].ch[0])
        {
            root=e[deal].ch[1];
            e[root].father=0;
        }
        else
        {
            long long lef=e[deal].ch[0];
            while(e[lef].ch[1]) lef=e[lef].ch[1];
            splay(lef,e[deal].ch[0]);
            long long rig=e[deal].ch[1];
            connect(rig,lef,1);connect(lef,0,1);
            update(lef);
        }
        destroy(deal);
    }
    long long rank(long long v)//获取值为v的元素在这棵树里是第几小
    {
        long long ans=0,now=root;
        while(true)
        {
            if(e[now].v==v) return ans+e[e[now].ch[0]].sum+1;
            if(now==0) return 0;
            if(v<e[now].v) now=e[now].ch[0];
            else
            {
                ans=ans+e[e[now].ch[0]].sum+e[now].recy;
                now=e[now].ch[1];
            }
        }
        if(now) splay(now,root);
        return 0;
    }
    long long atrank(long long x)//获取第x小的元素的值
    {
        if(x>points) return -INF;
        long long now=root;
        while(true)
        {
            long long minused=e[now].sum-e[e[now].ch[1]].sum;
            if(x>e[e[now].ch[0]].sum&&x<=minused) break;
            if(x<minused) now=e[now].ch[0];
            else
            {
                x=x-minused;
                now=e[now].ch[1];
            }
        }
        splay(now,root);
        return e[now].v;
    }
    long long upper(long long v)//后驱
    {
        long long now=root;
        long long result=INF;
        while(now)
        {
            if(e[now].v>v&&e[now].v<result) result=e[now].v;
            if(v<e[now].v) now=e[now].ch[0];
            else now=e[now].ch[1];
        }
        return result;
    }
    long long lower(long long v)//前驱
    {
        long long now=root;
        long long result=-INF;
        while(now)
        {
            if(e[now].v<v&&e[now].v>result) result=e[now].v;
            if(v>e[now].v) now=e[now].ch[1];
            else now=e[now].ch[0];
        }
        return result;
    }
    #undef root
};
Splay mysplay;
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,t,qwe;
    cin>>n>>t;
    mysplay.push(0);
    long long sum=0;
    long long ans=0;
    long long cnt=1;
    for(long long i=0;i<n;++i)
    {
        cin>>qwe;
        sum+=qwe;
        ++cnt;
        mysplay.push(sum-t+1);
        ans+=cnt-mysplay.rank(sum-t+1);
        mysplay.pop(sum-t+1);
        mysplay.push(sum);
    }
    cout<<ans<<endl;
    return 0;
}
