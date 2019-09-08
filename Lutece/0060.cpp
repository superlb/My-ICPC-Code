#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	int sum,len;
	string str;
	bool si;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++)
	{
		si = false;
		sum = 0;
		getline(cin, str);
		len = str.size();
		for (int j = 0; j < len; j++)
		{
			if (str[j] != ' ')
			{
				if (si == false)
				{
					si = true;
					sum++;
				}
			}
			else
			{
				si = false;
			}
		}
		cout << sum <<endl;
	}
	return 0;
}
