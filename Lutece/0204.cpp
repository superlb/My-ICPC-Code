#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int> > p;
	int n, a,b;
	long long sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		p.push(a);
	}
	for (int i = 0; i < n - 1;i++)
	{
		a = p.top(); p.pop();
		b = p.top(); p.pop();
		sum += a + b;
		p.push(a + b);
	}
	cout << sum;
	return 0;
}
