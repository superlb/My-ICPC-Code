#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	int t,n;
	string str;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> str;
		int len = str.size();
		int a = 0;
		int sum = str.size();
		for (int j = 0; j < len; j++)
		{
			if (str[j] == '0')
			{
				a++;
			}
			if (str[j] == '1'&& a > 0)
			{
				a--;
				sum -= 2;
			}
		}
		printf("%d.000\n",sum);
	}
	return 0;
}
