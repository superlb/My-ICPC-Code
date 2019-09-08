#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n;
	int a,b,now;
	int sum=0;
	priority_queue<int, vector<int>, greater<int> > c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		c.push(a);
	}
	for (int i = 0; i < n - 1; i++)
	{
		a = c.top(); c.pop();
		b = c.top(); c.pop();
		now = a + b;
		sum += now;
		c.push(now);
	}
	cout << sum;
	return 0;
}
