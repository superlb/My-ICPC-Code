#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, t;
	int s[100], d[100],e[100];
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> d[i];
		if (t > s[i])
		{
			e[i] = ((t - s[i]) / d[i])*d[i]+ s[i];
			if ((t - s[i]) % d[i])e[i] += d[i];
		}
		else
		{
			e[i] = s[i];
		}
	}
	int min = 200001;
	int asd = -1;
	for (int i = 0; i < n; i++)
	{
		if (e[i] < min)
		{
			min = e[i];
			asd = i;
		}
	}
	cout << asd + 1;
	return 0;
}
