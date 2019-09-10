#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct q
{
	int a, b;
}w[1001];
bool cmp1(q t, q e)
{
	return t.b < e.b;
}
int main()
{
	int n;
	double sum = 0;
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		w[i].a = i;
		cin >> w[i].b;
	}
	sort(w + 1, w + n + 1, cmp1);
	for (int i = 1; i < n; i++)
	{
		cout << w[i].a << " ";
		sum += (w[i].b) * (n-i);
	}
	cout << w[n].a <<endl;
	printf("%.2f", sum / n);
	return 0;
}
