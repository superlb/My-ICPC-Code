#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string str1,string str2)
{
	return str1 + str2 > str2 + str1;
}
int main()
{
	string str[20];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str,str+n,cmp);
	for (int i = 0; i < n; i++)
	{
		cout << str[i];
	}
	return 0;
}
