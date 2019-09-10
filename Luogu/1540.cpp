#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int m, n;
	int x;
	int num[100] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, };
	int sum=0;
	int muqian = 0;
	cin >> m >> n;
	for (int i=0;i<n;++i)
	{
		cin >> x;
		if (m == 0)
		{
			++sum;
			continue;
		}
		if (find(num,num+100,x) != num+100)
		{

		}
		else
		{
			if (muqian == m)
			{
				muqian = 0;
			}
			num[muqian] = x;
			++muqian;
			++sum;
		}
	}
	cout << sum;
	return 0;
}
