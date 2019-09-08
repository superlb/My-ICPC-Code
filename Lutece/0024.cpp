#include <cstdio>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)break;
		char s[20];
		int r=0, y=0;
		bool is;
		scanf("%s", s);
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'B')
			{
				is = true;
			}
			else if (s[i] == 'L')
			{
				is = false;
			}
			else if (s[i] == 'Y')
			{
				++y;
			}
			else if (s[i] == 'R')
			{
				++r;
			}
		}
		if (is)
		{
			if (r == 7)
			{
				printf("Red\n");
			}
			else
			{
				printf("Yellow\n");
			}
		}
		else
		{
			if (y == 7)
			{
				printf("Yellow\n");
			}
			else
			{
				printf("Red\n");
			}
		}
	}
	return 0;
}
