//Dinkelbach算法， 迭代求最优比率生成树
//此处是求解sigma(height)/sigma(dis)的最小值
//此处使用了kruskal来做生成树，实际上用prim会更快，对于完全图来说
struct edge
{
    int u,v;
    double height,dis,num;
    edge(){}
    edge(int _u,int _v,double _height,double _dis)
    {
        u=_u;v=_v;height=_height;dis=_dis;
    }
}edges[500005];
bool cmp(const edge &a,const edge &b)
{
    return a.num<b.num;
}
int n,tot=0,pos;//顶点数，边数，迭代时的边数
double k,k0=1.0,hsum,dsum;//上次迭代的值，这次迭代的值，height的和，dis的和
void Dinkelbach()
{
    while(1)
    {
        k=k0;hsum=0.0;dsum=0.0;pos=0;
        init(n);//并查集的初始化
        for(int i=0;i<tot;++i)
        {
            edges[i].num=edges[i].height-k*edges[i].dis;
        }
        //排序，并计算最小生成树
        sort(edges,edges+tot,cmp);
        for(int i=0;i<n-1;)
        {
            if(same(edges[pos].u,edges[pos].v))
            {
                ++pos;continue;
            }
            else
            {
                unite(edges[pos].u,edges[pos].v);
                hsum+=edges[pos].height;
                dsum+=edges[pos].dis;
                ++i;++pos;
            }
        }
        //此次最小生成树的值
        k0=hsum/dsum;
        if(fabs(k-k0)<0.000001)
            break;
    }
}
