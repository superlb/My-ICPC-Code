#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t,sum,len;
	string str;
	bool si;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> str;
		sum = 0;
		si = true;
		len = str.size();
		for (int j = 0; j < len; ++j)
		{
			if (str[j] == '(')
			{
				++sum;
			}
			else if (str[j] == ')')
			{
				if (sum > 0)
				{
					--sum;
				}
				else
				{
					si = false;
					break;
				}
			}
		}
		if (si && sum==0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
