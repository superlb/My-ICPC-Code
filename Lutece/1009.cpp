#include <iostream>
using namespace std;
int main()
{
	int n;
	int a;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		a = n % 10;
		switch (a)
		{
		case 0:
		case 1:
		case 5:
		case 6:
		case 9:
			cout << a << endl; break;
		case 2:
			if(n%4==0)
			{
				cout << 6 << endl;
			}
			else
			{
				cout << 4 << endl;
			}
			break;
		case 3:
			if(n % 4 == 3)
			{
				cout << 7 << endl;
			}
			else
			{
				cout << 3 << endl;
			}
			break;
		case 4:
			cout << 6 << endl; break;
		case 7:
			if (n % 4 == 1)
			{
				cout << 7 << endl;
			}
			else
			{
				cout << 3 << endl;
			}
			break;
		case 8:
			if (n % 4 == 0)
			{
				cout << 6 << endl;
			}
			else
			{
				cout << 4 << endl;
			}
			break;
		}
	}
	return 0;
}
