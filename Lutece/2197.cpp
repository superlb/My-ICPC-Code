#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int row, col, w, h;
		cin >> row >> col >> w >> h;
		cout << "Case #" << i << ":" << endl;
		cout << "+";
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < w; ++j)
			{
				cout << "-";
			}
			cout << "+";
		}
		cout << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < h; ++j)
			{
				cout << "|";
				for (int d1 = 0; d1 < col; d1++)
				{
					for (int d2 = 0; d2 < w; ++d2)
					{
						cout << "*";
					}
					cout << "|";
				}
				cout << endl;
			}
			cout << "+";
			for (int i1 = 0; i1 < col; i1++)
			{
				for (int j1 = 0; j1 < w; ++j1)
				{
					cout << "-";
				}
				cout << "+";
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}
