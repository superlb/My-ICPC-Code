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
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 3e18;
const unsigned long long HASHBASE=1222827239ull;
/////////////////////////
struct node
{
    int num=0;
    node *child[26];
};
void insert(string str, node *root)
{
    node *insertroot = root;
    int len = str.length();
    for(int i=0;i<len;++i)
    {
        if( (*insertroot).child[str[i]-'a'] == NULL)
        {
            (*insertroot).child[str[i]-'a'] = new node();
        }
        insertroot = (*insertroot).child[str[i]-'a'];
        (*insertroot).num++;
    }
}
int query(string str, node *root)
{
    node *queryroot = root;
    int len = str.length();
    for(int i=0;i<len;++i)
    {
        if( (*queryroot).child[str[i]-'a'] == NULL)
        {
            return 0;
        }
        queryroot = (*queryroot).child[str[i]-'a'];
    }
    return (*queryroot).num;
}
node *root1 = new node();
node *root2 = new node();
/////////////////////////
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    string tmp1,tmp2;
    for(int i=0;i<n;++i)
    {
        cin>>tmp2;
        tmp1 = tmp2;
        reverse(tmp2.begin(),tmp2.end());
        cout<<query(tmp1,root1)<<" "<<query(tmp2,root2)<<endl;
        insert(tmp1,root1);insert(tmp2,root2);
    }
    return 0;
}
