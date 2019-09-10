#include<bits/stdc++.h>
using namespace std;
int a[31];
int v,n;
int dp(int nown, int nowv)
{
	if (nown == n)return 0;
	if (a[nown] > nowv)
	{
		return dp(nown + 1, nowv);
	}
	else
	{
		return max(dp(nown + 1, nowv), dp(nown + 1, nowv - a[nown]) + a[nown]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> v >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << v - dp(0, v);
	//system("pause");
	return 0;
}
