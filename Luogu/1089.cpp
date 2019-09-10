#include<iostream>
using namespace std;
int main()
{
	int hand(0);
	int mother(0);
	int yusuan(0);
	int jieguo=0;
	for (int n = 1;n != 13;n++)
	{
		cin >> yusuan;
		hand += 300;
		if (hand >= yusuan)
		{
			hand -= yusuan;
			while (hand > 100)
			{
				hand -= 100;
				mother += 100;
			}
		}
		else
		{
			jieguo = -n;
			break;
		}

	}
	if (jieguo < 0)
	{
		cout << jieguo;
	}
	else
	{
		cout << (mother*1.2 + hand);
	}
	return 0;
}
