#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string str;
	set<string> s;
	for (int i = 0; i < 20000; ++i)
	{
		cin >> str;
		s.insert(str);
	}
	cout << s.size()<<endl;
	return 0;
}
