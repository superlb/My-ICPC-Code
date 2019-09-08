#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t, n, k;
	cin >> t;
	for (int i=0;i<t;i++)
	{
		cin >> n;
		k = 0;
		while ( pow(2,k) < n)
		{
			k++;
		}
		cout << k <<endl;
	}
	return 0;
}
