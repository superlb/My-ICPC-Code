#include <iostream>
using namespace std;
int main()
{
	int n, a;
	cin >> n >> a;
	while (n >= 500)
	{
		n -= 500;
	}
	if (n <= a)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
