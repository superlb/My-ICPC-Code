#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n,nown=1;
	while (cin>>n)
	{
		if (n == 0)break;
		int a[10][10];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> a[i][j];
			}
		}
		int sum = a[0][0];
		for (int i = 1; i < n-1; i++)
		{
			sum += a[i][0];
			sum += a[i][i];
		}
		for (int i = 0; i < n; i++)
		{
			sum += a[n-1][i];
		}
		if (n == 1)sum -= a[0][0];
		cout << "Case #"<<nown<<":" << sum << endl;
		nown++;
	}
	//system("pause");
	return 0;
}
