#include <iostream>
#include <algorithm>
using namespace std;
struct man
{
	int num, score;
}mans[5000];
bool comp(man a, man b)
{
	return a.score > b.score;
}
bool comp2(man a, man b)
{
	return a.num < b.num;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m,x,left=0,right=0;
	cin >> n >> m;
	m = m * 1.5;
	for (int i = 0; i < n; i++)
	{
		cin >> mans[i].num >> mans[i].score;
	}
	stable_sort(mans, mans + n, comp);
	x = mans[m - 1].score;
	while (1)
	{
		if (mans[right].score == mans[left].score)
		{
			++right;
		}
		else
		{
			stable_sort(mans + left, mans + right, comp2);
			left = right;
			if (mans[right].score < x)break;
		}
	}
	cout << x << " " << right<<endl;
	for (int i = 0; i < right; i++)
	{
		cout << mans[i].num << " " << mans[i].score << endl;
	}
	return 0;
}
