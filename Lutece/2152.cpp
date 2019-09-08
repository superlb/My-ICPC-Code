#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
struct node
{
	int id, value;
	node(){}
	node(int _id, int _value)
	{
		id = _id; value = _value;
	}
	bool operator <(const node &a)const
	{
		return value < a.value;
	}

}nodes[MAXN];
int isqueue[MAXN],Left[MAXN],Right[MAXN];
int m, n, a,sum=0,leftnode,rightnode;
priority_queue<node> p;
node linshi;
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(isqueue, 0, sizeof(isqueue));
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		nodes[i] = node(i, a);
		Left[i] = i - 1; Right[i] = i + 1;
		p.push(nodes[i]);
	}
	Left[1] = n; Right[n] = 1;
	if (m > n / 2)
	{
		cout << "Error!";
	}
	else
	{
		for (int i = 1; i <= m; ++i)
		{
			linshi = p.top(); p.pop();
			while (isqueue[linshi.id])
			{
				linshi = p.top(); p.pop();
			}
			leftnode = Left[linshi.id];
			rightnode = Right[linshi.id];
			isqueue[leftnode] = 1; isqueue[rightnode] = 1;
			Right[Left[leftnode]] = linshi.id;
			Left[Right[rightnode]] = linshi.id;
			Left[linshi.id] = Left[leftnode];
			Right[linshi.id] = Right[rightnode];
			sum += linshi.value;
			nodes[linshi.id].value = nodes[leftnode].value + nodes[rightnode].value - nodes[linshi.id].value;
			linshi.value = nodes[linshi.id].value;
			p.push(linshi);
		}
		cout << sum;
	}
	//system("pause");
	return 0;
}
