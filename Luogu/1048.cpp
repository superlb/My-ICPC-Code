#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int t, n;
int w[101], q[101];
int dp[101][1001];
int rec(int i, int j)
{
	if (dp[i][j] >= 0)
	{
		return dp[i][j];
	}
	int res;
	if (i == n)
	{
		res = 0;
	}
	else if(j<w[i])
	{
		res = rec(i + 1, j);
	}
	else
	{
		res = max(rec(i+1,j),rec(i+1,j-w[i])+q[i]);
	}
	return dp[i][j] = res;
}
int main()
{
	cin >> t >> n;
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < n;i++)
	{
		cin >> w[i] >> q[i];
	}
	cout << rec(0,t);
	return 0;
}
