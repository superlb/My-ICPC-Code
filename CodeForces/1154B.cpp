#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	set<int> s;
	set<int>::iterator ite;
	int n,a;
	bool is = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.insert(a);
	}

	if (s.size() == 1)
	{
		cout << 0;
	}
	else if (s.size() == 2)
	{
		int qwe = (*(--s.end()) - *s.begin());
		if (qwe % 2 == 0)
		{
			cout << qwe / 2;
		}
		else
		{
			cout << qwe;
		}
	}
	else if (s.size() == 3)
	{
		int q, w, e;
		ite = s.begin();
		q = *ite; ite++;
		w = *ite; ite++;
		e = *ite;
		if (w - q == e - w)
		{
			cout << w - q;
		}
		else
		{
			cout << -1;
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}
