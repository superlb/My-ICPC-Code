#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int num[6] = {100,100,100,100,100,100};
	int sum = 0;
	string str;
	for (int i = 0; i < 7; i++)
	{
		cin >> str;
		if (str == ".")
		{
			break;
		}
		if (str == "one")
		{
			num[i] = 1;
			++sum;
		}
		else if (str == "two")
		{
			num[i] = 4;
			++sum;
		}
		else if (str == "three")
		{
			num[i] = 9;
			++sum;
		}
		else if (str == "four")
		{
			num[i] = 16;
			++sum;
		}
		else if (str == "five")
		{
			num[i] = 25;
			++sum;
		}
		else if (str == "six")
		{
			num[i] = 36;
			++sum;
		}
		else if (str == "seven")
		{
			num[i] = 49;
			++sum;
		}
		else if (str == "eight")
		{
			num[i] = 64;
			++sum;
		}
		else if (str == "nine")
		{
			num[i] = 81;
			++sum;
		}
		else if (str == "ten")
		{
			num[i] = 0;
			++sum;
		}
		else if (str == "eleven")
		{
			num[i] = 21;
			++sum;
		}
		else if (str == "twelve")
		{
			num[i] = 44;
			++sum;
		}
		else if (str == "thirteen")
		{
			num[i] = 69;
			++sum;
		}
		else if (str == "fourteen")
		{
			num[i] = 96;
			++sum;
		}
		else if (str == "fifteen")
		{
			num[i] = 25;
			++sum;
		}
		else if (str == "sixteen")
		{
			num[i] = 56;
			++sum;
		}
		else if (str == "seventeen")
		{
			num[i] = 89;
			++sum;
		}
		else if (str == "eighteen")
		{
			num[i] = 24;
			++sum;
		}
		else if (str == "nineteen")
		{
			num[i] = 61;
			++sum;
		}
		else if (str == "twenty")
		{
			num[i] = 0;
			++sum;
		}
		else if (str == "a")
		{
			num[i] = 1;
			++sum;
		}
		else if (str == "both")
		{
			num[i] = 4;
			++sum;
		}
		else if (str == "another")
		{
			num[i] = 1;
			++sum;
		}
		else if (str == "first")
		{
			num[i] = 1;
			++sum;
		}
		else if (str == "second")
		{
			num[i] = 4;
			++sum;
		}
		else if (str == "third")
		{
			num[i] = 9;
			++sum;
		}
	}
	sort(num, num + 6);
	if (sum == 0)
	{
		cout << 0;
	}
	else
	{
		cout << num[0];
		for (int i = 1; i < sum; i++)
		{
			if (num[i] < 10)
			{
				cout << "0" << num[i];
			}
			else
			{
				cout << num[i];
			}
		}
	}
	return 0;
}
