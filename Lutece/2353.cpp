#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,k,t;
	int sum;
	cin >> n >> m >> k >> t;
	sum = n * m / min(k,n);
	if ((n*m) % k != 0 && n>k)
	{
		++sum;
	}
	cout << sum*t;
	return 0;
}
