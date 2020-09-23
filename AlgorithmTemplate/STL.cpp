//STL相关算法
//String
#include <string>
string str="12345678";
string str2="9";
str.size();//8
str.append(str2);//123456789
str.append(100,'0');//加一百个零
string::size_type m=str.find("3",0);//寻找的字符，从哪一位开始寻找
str.erase(m,3);//126789
str.substr(start_pos,len);
//Algorithm
#include <algorithm>
int a[5]={1,3,4,2,5};
sort(a,a+5,compare_function);
stable_sort(...);//稳定排序
int *p=find(a,a+5,4);//找不到则p==a+5，找到则为物理地址
binary_search(a,a+5,4);//返回true或false
lower_bound(a,a+5,4);//返回 值,降序序列用
upper_bound(a,a+5,4);//升序序列用
//栈
#include <stack>
stack<int> s;
s.push();//入栈
s.pop();//出栈
s.top();//取栈顶值
//队列
#include <queue>
queue<int> que;
que.push();//入队列
que.pop();//出队列
que.front();//取队列底值
//优先队列
#include <queue>
priority_queue<int> pque;//先出最大值
priority_queue<int,vector<int>,greater<int> > pque;//先出最小值
pque.push();//入队列
pque.pop();//最值出队列
pque.top();//取队列最值
//
#include <set>
set<int> s;
set<int>::iterator ite;
s.insert(1);
ite=s.find(1);
if(ite == s.end())
for(ite = s.begin();ite!=s.end();++ite)
s.erase(1);
//
#include <map>
map<int ,const char*> m;
m.insert(make_pair(1,"one"));
m[2]="two";
map<int ,const char*>::iterator ite;
ite = m.find(1);
if(ite!=m.end()) puts(ite->second);
puts(m[2]);
m.erase(1);
//
#include <vector>
vector<int> v;
v.push_back(x);
