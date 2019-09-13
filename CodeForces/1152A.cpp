#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, m,a,s1=0,s2=0,s3=0,s4=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a % 2)
		{
			++s1;
		}
		else
		{
			++s2;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (a % 2)
		{
			++s3;
		}
		else
		{
			++s4;
		}
	}
	cout << min(s1, s4) + min(s2, s3);
	return 0;
}
