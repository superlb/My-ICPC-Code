#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int t,a,b,c;
	int q[10][10], w[10][10],e[10][10];
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		memset(q, 0, sizeof(q));
		memset(w, 0, sizeof(w));
		memset(e, 0, sizeof(e));
		cin >> a >> b >> c;
		for (int d1 = 0; d1 < a; d1++)
		{
			for (int d2 = 0; d2 < b; d2++)
			{
				cin >> q[d1][d2];
			}
		}
		for (int d1 = 0; d1 < b; d1++)
		{
			for (int d2 = 0; d2 < c; d2++)
			{
				cin >> w[d1][d2];
			}
		}
		for (int d1 = 0; d1 < a; d1++)
		{
			for (int d2 = 0; d2 < c; d2++)
			{
				for (int d3 = 0; d3 < b; d3++)
				{
					e[d1][d2] += q[d1][d3] * w[d3][d2];
				}
			}
		}
		for (int d1 = 0; d1 < a; d1++)
		{
			for (int d2 = 0; d2 < c; d2++)
			{
				cout << e[d1][d2];
				if (d2 == c - 1)
				{
					cout << endl;
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}
