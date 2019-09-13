#include<bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
int main()
{
	ios::sync_with_stdio(false);
	int n,qwe;
	int q1 = 0, q2 = 0,last=0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> qwe;
		a[i] = qwe;
		b[n - i - 1] = qwe;
	}
	while (n--)
	{
		if (a[q1] > b[q2])
		{
			if (b[q2] > last)
			{
				str.append("R");
				last = b[q2];
				q2++;
			}
			else
			{
				if (a[q1] > last)
				{
					str.append("L");
					last = a[q1];
					q1++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			if (a[q1] > last)
			{
				str.append("L");
				last = a[q1];
				q1++;
			}
			else
			{
				if (b[q2] > last)
				{
					str.append("R");
					last = b[q2];
					q2++;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << str.length()<<endl;
	cout << str;
	return 0;
}
