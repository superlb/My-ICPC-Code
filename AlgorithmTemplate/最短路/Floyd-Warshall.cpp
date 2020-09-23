//Floyd-Warshall算法， 求解任意两点间的距离
int d[MAX_V][MAX_V];
int V;
void Floyd_Warshall()
{
    for(int k=0;k<V;++k)
        for(int i=0;i<V;++i)
            for(int j=0;j<V;++j)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
