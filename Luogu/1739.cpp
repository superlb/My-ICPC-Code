#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string str;
	int n=0;
	bool is = true;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			n++;
		}
		else if(str[i]==')')
		{
			if (n > 0)
			{
				n--;
			}
			else
			{
				is = false;
				break;
			}
		}
	}
	if (is && n == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
