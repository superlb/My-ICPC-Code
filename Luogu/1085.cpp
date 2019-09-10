#include<iostream>
using namespace std;
int main()
{
	int a, b, c=0;
	bool abc=true;
	for (int n = 0;n != 7;++n)
	{
		cin >> a >> b;
		if (a + b > 8 && abc)
		{
			c = n + 1;
			abc = false;
		}
	}
	cout << c;
	return 0;
}
