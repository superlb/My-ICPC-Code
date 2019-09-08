#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int strnum[100000];
int main()
{
	string str;
	int len;
	int num[26];
	int lin[26];
	int sum1=0;
	int q;
	bool isok=false;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len; ++i)
	{
		strnum[i] = str[i] - 97;
	}
	for (int i = 0; i < 26; i++)
	{
		cin >> num[i];
		sum1 += num[i];
	}
	for (int i = 0; i < len ; ++i)
	{
		if (isok)
		{
			break;
		}
		memset(lin,0,sizeof(lin));
		for (int j = 0; j <= sum1; ++j)
		{
			if (sum1 == j)
			{
				isok = true;
				break;
			}
			++lin[strnum[i+j]];
			if (lin[strnum[i + j]] > num[strnum[i + j]])
			{
				break;
			}
		}
	}
	if (isok)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}
