#include <iostream>
#include <algorithm>
using namespace std;
struct com
{
	int a, b;
}coms[1000000];
bool cmp(com x,com y)
{
	return x.b < y.b;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, last = 0, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> coms[i].a >> coms[i].b;
	}
	sort(coms,coms+n,cmp);
	for (int i = 0; i < n; i++)
	{
		if (coms[i].a >= last)
		{
			++sum;
			last = coms[i].b;
		}
	}
	cout << sum;
	return 0;
}
