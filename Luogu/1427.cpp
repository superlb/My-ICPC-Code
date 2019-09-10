#include<iostream>

using namespace std;
int main()
{
	int shuzi[100]{};
	int n(-1);
	do
	{
		++n;
		cin >> shuzi[n];
	} while (shuzi[n] != 0);
	while (n !=0)
	{
		--n;
		cout << shuzi[n];
		if (n != 0)
		{
			cout << " ";
		}
	}

	return 0;
}
