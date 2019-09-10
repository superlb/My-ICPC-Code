#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n1, n2, n3;
	for (n1 = 123;n1 != 334;n1++)
	{
		n2 = 2 * n1;
		n3 = 3 * n1;
		set<int> shuzi;
		shuzi.insert(n1 / 100);
		shuzi.insert((n1 % 100)/10);
		shuzi.insert(n1 % 10);
		shuzi.insert((n2 % 100) / 10);
		shuzi.insert(n2 / 10);
		shuzi.insert(n2 % 10);
		shuzi.insert(n3 / 100);
		shuzi.insert((n3 % 100) / 10);
		shuzi.insert(n3 % 10);
		int x = shuzi.size();
		if (x == 9 && *shuzi.begin()==1)
		{
				cout << n1 << " " << n2 << " " << n3 << endl;
		}

	}
	return 0;
}
