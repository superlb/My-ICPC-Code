#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string str1,str2;
	string str3 = "abcdefghijklmnopqrstuvwxyz";
	cin >> n;
	cin >> str1;
	int len = str1.length();
	int j;
	for (int i = 0; i < len; ++i)
	{
		j=str3.find(str1[i],0);
		if (j + n >= 26)
		{
			str2.append(str3, j + n-26, 1);
		}
		else
		{
			str2.append(str3, j + n, 1);
		}
	}
	cout << str2;
	return 0;
}
