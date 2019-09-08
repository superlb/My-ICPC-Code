#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		if (n == 0)break;
		while (true)
		{
			int target[1000];
			cin >> target[0];
			if (target[0])
			{
				stack<int> s;
				for (int i = 1; i < n; ++i)
				{
					cin >> target[i];
				}
				int A = 1, B = 0, ok = 1;
				while (B < n)
				{
					if (A == target[B])
					{
						A++; B++;
					}
					else if (!s.empty() && s.top() == target[B])
					{
						s.pop(); B++;
					}
					else if (A <= n)
					{
						s.push(A++);
					}
					else
					{
						ok = 0; break;
					}
				}
				if (ok)
				{
					cout << "Yes" << endl;
				}
				else
				{
					cout << "No" << endl;
				}
			}
			else
			{
				cout << endl;
				break;
			}
		}
	}
	//system("pause");
	return 0;
}
