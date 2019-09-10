#include<iostream>

using namespace std;
int main()
{
	int apple[10];
	int hand;
	int sum;
	for (int n = 0;n != 10;++n)
	{
		cin >> apple[n];
	}
	cin >> hand;
	for (int k = 0;k != 10;++k)
	{
		if (apple[k] <= (hand+30))
		{
			++sum;
		}
	}
	cout << sum;
	return 0;
}
