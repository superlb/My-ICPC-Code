#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string str;
	char strnum[10];
	int is[10];
	int a;
	int strlen;
	cin >> strlen >> str;
	for (int i = 1; i <= 9; ++i)
	{
		cin >> a;
		if (a > i)
		{
			switch (a)
			{
			case 1:
				strnum[i] = '1';
				break;
			case 2:
				strnum[i] = '2';
				break;
			case 3:
				strnum[i] = '3';
				break;
			case 4:
				strnum[i] = '4';
				break;
			case 5:
				strnum[i] = '5';
				break;
			case 6:
				strnum[i] = '6';
				break;
			case 7:
				strnum[i] = '7';
				break;
			case 8:
				strnum[i] = '8';
				break;
			case 9:
				strnum[i] = '9';
				break;
			}
			is[i] = 1;
		}
		else if(a == i)
		{
			switch (i)
			{
			case 1:
				strnum[i] = '1';
				break;
			case 2:
				strnum[i] = '2';
				break;
			case 3:
				strnum[i] = '3';
				break;
			case 4:
				strnum[i] = '4';
				break;
			case 5:
				strnum[i] = '5';
				break;
			case 6:
				strnum[i] = '6';
				break;
			case 7:
				strnum[i] = '7';
				break;
			case 8:
				strnum[i] = '8';
				break;
			case 9:
				strnum[i] = '9';
				break;
			}
			is[i] = 0;
		}
		else if (a < i)
		{
			switch (i)
			{
			case 1:
				strnum[i] = '1';
				break;
			case 2:
				strnum[i] = '2';
				break;
			case 3:
				strnum[i] = '3';
				break;
			case 4:
				strnum[i] = '4';
				break;
			case 5:
				strnum[i] = '5';
				break;
			case 6:
				strnum[i] = '6';
				break;
			case 7:
				strnum[i] = '7';
				break;
			case 8:
				strnum[i] = '8';
				break;
			case 9:
				strnum[i] = '9';
				break;
			}
			is[i] = -1;
		}
	}
	bool isis = false;
	int asd;
	for (int i = 0; i < strlen; ++i)
	{
		switch (str[i])
		{
		case '1':
			asd = 1;
			break;
		case '2':
			asd = 2;
			break;
		case '3':
			asd = 3;
			break;
		case '4':
			asd = 4;
			break;
		case '5':
			asd = 5;
			break;
		case '6':
			asd = 6;
			break;
		case '7':
			asd = 7;
			break;
		case '8':
			asd = 8;
			break;
		case '9':
			asd = 9;
			break;
		}
		if (isis == false && is[asd] == 1 )
		{
			isis = true;
		}
		if (isis == true && is[asd] == 1)
		{
			str[i] = strnum[asd];
		}
		else if (isis == true && is[asd] == -1)
		{
			break;
		}
	}
	cout << str;
	return 0;
}
