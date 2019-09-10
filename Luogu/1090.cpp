#include <iostream>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int> > pque;
	int n,x,a,b,sum=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		pque.push(x);
	}
	for (int i = 0; i < n - 1; i++)
	{
		a = pque.top(); pque.pop();
		b = pque.top(); pque.pop();
		sum += a + b;
		pque.push(a+b);
	}
	cout << sum;
	return 0;
}
