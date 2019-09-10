#include<iostream>

using namespace std;
int main()
{
	int L;
	int M;
	cin >> L >> M;
	int tree[10001]{};
	int sum(0);
	for (int n1 = 0;n1 <= L;++n1)
	{
		tree[n1] = 1;
	}
	for (int n2 = 1;n2 <= M;++n2)
	{
		int tou, wei;
		cin >> tou >> wei;
		for (int n3 = tou;n3 <= wei;++n3)
		{
			tree[n3] = 0;
		}
	}
	for (int n4 = 0;n4 <= L;n4++)
	{
		if (tree[n4] == 1)
		{
			++sum;
		}
	}
	cout << sum;
	return 0;
}
