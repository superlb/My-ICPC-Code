#include<bits/stdc++.h>
using namespace std;
const unsigned long long base = 131;
const unsigned long long prime = 233317;
const unsigned long long modnum = 212370440130137957ll;
unsigned long long a[10000];
unsigned long long myhash(string s)
{
	int len = s.length();
	unsigned long long sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum = (sum * base + (unsigned long long)s[i]) % modnum + prime;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string str;
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		a[i] = myhash(str);
	}
	sort(a,a+n);
	for (int i = 0; i < n-1; ++i)
	{
		if (a[i] != a[i + 1])
		{
			++ans;
		}
	}
	cout << ans;
	//system("pause");
	return 0;
}
