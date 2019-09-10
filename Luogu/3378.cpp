#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	priority_queue<int , vector<int> , greater<int> > p;
	int n,a,b;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b;
			p.push(b);
		}
		else if (a == 2)
		{
			cout << p.top() << endl;
		}
		else if (a == 3)
		{
			p.pop();
		}
	}
	return 0;
}
