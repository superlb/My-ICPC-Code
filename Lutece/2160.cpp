#include<bits/stdc++.h>
using namespace std;
struct node
{
	int childsum[2];
	node *child[2];
	node()
	{
		childsum[0] = 0; childsum[1] = 0;
		child[0] = NULL; child[1] = NULL;
	}
};
node *root;
void addnode(int num)
{
	node *p = root;
	int bit;
	for (int i = 30; i >= 0; --i)
	{
		bit = (num&(1<<i)) ? 1 : 0;
		if (p->child[bit]==NULL)
		{
			p->child[bit] = new node();
		}
		++p->childsum[bit];
		p = p->child[bit];
	}
}
void delnode(int num)
{
	node *p = root;
	int bit;
	for (int i = 30; i >= 0; --i)
	{
		bit = (num&(1 << i)) ? 1 : 0;
		--p->childsum[bit];
		p = p->child[bit];
	}
}
int solvemax(int num)
{
	node *p = root;
	int bit;
	bool is;
	int ans=0;
	for (int i = 30; i >= 0; --i)
	{
		bit = (num&(1 << i)) ? 1 : 0;
		if (p->child[bit ^ 1] != NULL && p->childsum[bit ^ 1] != 0)
		{
			p = p->child[bit ^ 1];
			is = true;
		}
		else
		{
			p = p->child[bit];
			is = false;
		}
		if (is)
		{
			ans += (1 << i);
		}
	}
	return ans;
}
int solvemin(int num)
{
	node *p = root;
	int bit;
	bool is;
	int ans = 0;
	for (int i = 30; i >= 0; --i)
	{
		bit = (num&(1 << i)) ? 1 : 0;
		if (p->child[bit] != NULL && p->childsum[bit] != 0)
		{
			p = p->child[bit];
			is = false;
		}
		else
		{
			p = p->child[bit ^ 1];
			is = true;
		}
		if (is)
		{
			ans += (1 << i);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n,o,v;
	root = new node();
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> o >> v;
		if (o == 1)
		{
			addnode(v);
		}
		else if (o == 2)
		{
			delnode(v);
		}
		else if (o == 3)
		{
			cout << solvemin(v) << " " << solvemax(v) << endl;
		}
	}
	return 0;
}
