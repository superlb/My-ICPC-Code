#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n,x,len;
	set<int> s;
	set<int>::iterator it,it2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s.insert(x);
	}
	len = s.size();
	cout << len << endl;
	it2 = s.end();
	it2--;
	for (it = s.begin(); it != it2; it++)
	{
		cout << (*it) << " ";
	}
	cout << (*it);
	return 0;
}
