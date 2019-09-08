#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n;
	string str;
	set<string> s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		s.insert(str);
	}
	cout << s.size();
	return 0;
}
