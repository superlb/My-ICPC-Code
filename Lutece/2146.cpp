#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	char qwe[16] = {'f','e','d','c','b','a','9','8','7','6','5','4','3','2','1','0'};
	char linshi;
	while (cin>>n>>k)
	{
		vector<int> s[16];
		for (int i = 0; i < n; ++i)
		{
			cin >> linshi;
			switch (linshi)
			{
			case 'f':
				s[0].push_back(i);
				break;
			case 'e':
				s[1].push_back(i);
				break;
			case 'd':
				s[2].push_back(i);
				break;
			case 'c':
				s[3].push_back(i);
				break;
			case 'b':
				s[4].push_back(i);
				break;
			case 'a':
				s[5].push_back(i);
				break;
			case '9':
				s[6].push_back(i);
				break;
			case '8':
				s[7].push_back(i);
				break;
			case '7':
				s[8].push_back(i);
				break;
			case '6':
				s[9].push_back(i);
				break;
			case '5':
				s[10].push_back(i);
				break;
			case '4':
				s[11].push_back(i);
				break;
			case '3':
				s[12].push_back(i);
				break;
			case '2':
				s[13].push_back(i);
				break;
			case '1':
				s[14].push_back(i);
				break;
			case '0':
				s[15].push_back(i);
				break;
			}
		}
		int now = 0;
		vector<int>::iterator it1, it2[16];
		for (int j = 0; j < 16; ++j)
		{
			it2[j] = s[j].end();
		}
		for (int i = 0; i < k; ++i)
		{
			for (int j = 0; j < 16; ++j)
			{
				it1=lower_bound(s[j].begin(), s[j].end(),now);
				if (it1 != it2[j] && *it1+ k - i <= n)
				{
					cout << qwe[j];
					now = *it1+1;
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
