#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int a[128],len,sum=0;
	string str1,str2;
	bool is = true;
	fill(a, a + 128, 0);
	cin >> str1>>str2;
	len = str1.length();
	for (int i = 0; i < len; ++i)
	{
		if (a[str1[i]] == 0)
		{
			for (int j = 65; j < 91; j++)
			{
				if (a[j] == str2[i])
				{
					is = false;
					break;
				}
			}
			a[str1[i]] = str2[i];
			++sum;
		}
		else
		{
			if (a[str1[i]] == str2[i])
			{
				continue;
			}
			else
			{
				is = false;
			}
		}
	}
	cin >> str1;
	len = str1.length();
	if (is && sum == 26)
	{
		for (int i = 0; i < len; i++)
		{
			cout << (char)a[str1[i]];
		}
	}
	else
	{
		cout << "Failed";
	}
	return 0;
}
