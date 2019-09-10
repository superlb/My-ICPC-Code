#include<cstdio>
#include<algorithm>
using namespace std;
struct Person{
    int id,w;
}p[10000001]; //结构体，方便些
int n,k,E[11];
bool cmp(Person,Person); //排序的函数
int main(){
    scanf("%d%d",&n,&k); //输入
    for(int i=1;i<=10;i++) scanf("%d",&E[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].w);
        p[i].id=i+1;
    }
    sort(p,p+n,cmp); //sort函数，需带algorithm头文件
    for(int i=0;i<n;i++)
        p[i].w+=E[i%10+1];
    sort(p,p+n,cmp);
    for(int i=0;i<k;i++) printf("%d ",p[i].id); //输出
    return 0;
}
bool cmp(Person a,Person b){
    if(a.w==b.w) return a.id<b.id;
    return a.w>b.w;
}
