#include<bits/stdc++.h>
using namespace std;
long long qGCD(long long a, long long b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (!(a & 1) && !(b & 1))
		return qGCD(a >> 1, b >> 1) << 1;
	else if (!(b & 1))
		return qGCD(a, b >> 1);
	else if (!(a & 1))
		return qGCD(a >> 1, b);
	else
		return qGCD(abs(a - b), min(a, b));
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	long long qwe,last,startpoint;
	bool is = false;
	long long pj;
	cin >> n >> m;
	vector<long long> v1, v2;
	cin >> last;
	startpoint = last;
	for (int i = 1; i < n; ++i)
	{
		cin >> qwe;
		v1.push_back(qwe-last);
		last = qwe;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> qwe;
		v2.push_back(qwe);
	}
	if (v1.size() == 1)
	{
		long long asd = v1[0];
		for (vector<long long>::iterator it1 = v2.begin(), it2 = v2.end(); it1 != it2; ++it1)
		{
			if (asd % (*it1) == 0)
			{
				is = true;
				pj = it1 - v2.begin();
				break;
			}
		}
	}
	else
	{
		long long gbs;
		vector<long long>::iterator it1 = v1.begin(), it2 = v1.end(),it3= v1.begin();
		it3++;
		gbs = qGCD(*it1,*it3);
		++it3;
		for (; it3 != it2; ++it3)
		{
			gbs = qGCD(gbs,*it3);
		}
		for (vector<long long>::iterator it11 = v2.begin(), it21 = v2.end(); it11 != it21; ++it11)
		{
			if (gbs % (*it11) == 0)
			{
				is = true;
				pj = it11 - v2.begin();
				break;
			}
		}
	}
	if (is)
	{
		cout << "YES" << endl;
		cout << startpoint << " " << pj + 1;
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
