#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,sum=0;
	string str;
	cin >> n >> str;
	n = n - 10;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '8')
			++sum;
	}
	if (sum >= n / 2 + 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
