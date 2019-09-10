#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0, cishu = 0;;
	int a[10000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sum /= n;
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] < sum)
		{
			a[i + 1] -= sum - a[i];
			a[i] = sum;
			++cishu;
		}
		else if(a[i] > sum)
		{
			a[i + 1] += a[i] - sum;
			a[i] = sum;
			++cishu;
		}
		else
		{

		}
	}
	cout << cishu;
	return 0;
}
