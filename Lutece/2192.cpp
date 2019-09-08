#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		cout << "Case # " << i << ":" << endl;
		do
		{
			cout << str << endl;
		} while (next_permutation(str.begin(), str.end()));
	}
	//system("pause");
	return 0;
}
