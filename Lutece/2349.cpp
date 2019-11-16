#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	long n, m, L, R, a, b, c, d;
	cin >> T;
	for (int i = 0; i < T; ++i) { cin >> n >> m >> L >> R >> a >> b >> c >> d;
		if (b > L && b < R)
		{
			if (a != c)
			{
				cout << abs(a - c) + min( ( abs(b - L) + abs(d - L) ), ( abs(b - R) + abs(d - R))) << endl;
			}
			else
			{
				cout << abs(b - d) << endl;
			}
		}
		else
		{
			cout << abs(a - c) + abs(b - d) << endl;
		}
	}
	return 0;
}
