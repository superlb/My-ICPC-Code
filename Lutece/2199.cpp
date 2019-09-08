#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin>>n)
	{
		if (n == -1)break;
		int sum = 0;
		int a[11], b[11];
		b[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i] >> b[i];
			sum += a[i] * (b[i] - b[i - 1]);
		}
		cout << sum <<" miles"<< endl;
	}
	//system("pause");
	return 0;
}
