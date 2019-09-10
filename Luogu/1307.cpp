#include<iostream>
#include<string>
using namespace std;
int main()
{
	string in,out("");
	size_t len;
	bool youxiao(false);
	cin >> in;
	len = in.length();
	if (in[0] == '-')
	{
		out = "-";
		for (int n = len - 1;n >= 1;--n)
		{
			if (in[n] == '0' && youxiao==false)
			{
				continue;
			}
			else
			{
				youxiao = true;
				out += in[n];
			}
		}
	}
	else
	{
		for (int n = len - 1;n >= 0;--n)
		{
			if (in[n] == '0' && youxiao==false)
			{
				continue;
			}
			else
			{
				youxiao = true;
				out += in[n];
			}
		}
	}
	cout << out;
	return 0;
}
