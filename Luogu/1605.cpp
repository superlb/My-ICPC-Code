#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int b[10][10];
int n, m, t, sx, sy, fx, fy,x,y;
int search(int q, int w)
{
	if (b[q][w] == 0)
	{
		if (q == 0 || w == 0 || q > n || w > m)return 0;
		if (a[q][w] == 1)return 0;
		if (q == fx && w == fy)return 1;
		b[q][w] = 1;
		int ans = search(q - 1, w) + search(q, w-1) + search(q +1, w) + search(q, w+1);
		b[q][w] = 0;
		return ans;
	}
	else
	{
		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	memset(a,0,sizeof(a));
	memset(b,0, sizeof(b));
	for (int i = 0; i < t; i++)
	{
		cin >> x >> y;
		a[x][y] = 1;
	}
	cout << search(sx, sy);
	return 0;
}
