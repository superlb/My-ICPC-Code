#include<iostream>

using namespace std;
int main()
{
	float k,n(0),n1(2);
	int n2(0);
	cin >> k;
	while (k > n)
	{
		n += n1;
		n1 *= 0.98;
		++n2;
	}
	cout << n2;
	return 0;
}
