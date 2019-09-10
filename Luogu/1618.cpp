#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n1, n2, n3,a,b,c;
	bool iso = false;
	cin >> a >> b >> c;
	for (n1 = 123; n1 != 999; n1++)
	{
		n2 = n1 * b / a;
		n3 = n1 * c / a;
		if (n2 > 1000 || n3 > 1000)
		{
			break;
		}
		set<int> shuzi;
		shuzi.insert(n1 / 100);
		shuzi.insert((n1 % 100) / 10);
		shuzi.insert(n1 % 10);
		shuzi.insert((n2 % 100) / 10);
		shuzi.insert(n2 / 10);
		shuzi.insert(n2 % 10);
		shuzi.insert(n3 / 100);
		shuzi.insert((n3 % 100) / 10);
		shuzi.insert(n3 % 10);
		int x = shuzi.size();
		if (x == 9)
		{
			if (*shuzi.begin() == 1)
			{
				set<int>::iterator it=shuzi.end();
				--it; --it;
				if ( *it == 9)
				{
					iso = true;
					cout << n1 << " " << n2 << " " << n3 << endl;
				}
			}
		}
	}
	if (!iso)
	{
		cout << "No!!!";
	}
	return 0;
}
