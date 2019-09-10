#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int par[10000];
int rank1[10000];
void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		rank1[i] = 0;
	}
}
int find(int x)
{
	if (par[x] == x)
	{
		return x;
	}
	else
	{
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (rank1[x] < rank1[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (rank1[x] == rank1[y])rank1[x]++;
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	int n1,m1;
	int z1, x1, y1;
	cin >> n1 >> m1;
	init(n1);
	for (int i = 0; i < m1; i++)
	{
		cin >> z1 >> x1 >> y1;
		if (z1 == 1)
		{
			unite(x1,y1);
		}
		else if (z1 == 2)
		{
			if (same(x1, y1))
			{
				cout << "Y" << endl;
			}
			else
			{
				cout << "N" << endl;
			}
		}
	}
	return 0;
}
