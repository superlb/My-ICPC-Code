#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int r, g;
	cin >> r >> g;
	if ((abs(r - g) > 1) || (r==0&&g==0))
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}
	return 0;
}
