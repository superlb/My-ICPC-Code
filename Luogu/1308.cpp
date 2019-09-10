#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int main()
{
	string in;
	string allline;
	long first=-1;
	long sum = 0;
	long strleng;
	string str;
	getline(cin, in);
	getline(cin,allline);
	transform(in.begin(), in.end(), in.begin(), ::tolower);
	transform(allline.begin(), allline.end(), allline.begin(), ::tolower);
	strleng = allline.length();
	for (long i = 0; i <= strleng; ++i)
	{
		if (allline[i] == ' ' || i== strleng)
		{
			if (str.compare(in)==0)
			{
				if (first == -1)first = i-in.length();
				++sum;
				str = "";
				continue;
			}
			else
			{
				str = "";
				continue;
			}
		}
		str.append(allline,i,1);
	}
	if (first == -1)
		cout << first;
	else
		cout << sum << ' '<<first;
	cin >> in;
	return 0;
}
