#include <iostream>
using namespace std;
int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)break;
		cout << 8 * n - 4 << endl;
	}
	return 0;
}
