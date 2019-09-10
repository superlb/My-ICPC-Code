#include<iostream>
using namespace std;
int main()
{
	int a, b,c,d;
	cin >> a >> b >> c >> d;
	int aa, bb,cc;
	aa = c - a;
	bb = d - b;
	if (bb < 0) { --aa; cc = bb + 60; }
	if (bb >=0) { cc = bb; }
	cout << aa << " " << cc;
	return 0;
}
