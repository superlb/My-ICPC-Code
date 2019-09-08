#include<bits/stdc++.h>
using namespace std;
struct team
{
	int timu, fashi,name;
	team()
	{
		timu = 0; fashi = 0;
	}
	friend bool operator>(const team& a, const team& b)
	{
		if (a.timu > b.timu)
		{
			return true;
		}
		else if(a.timu == b.timu)
		{
			return a.fashi < b.fashi;
		}
		else if (a.timu < b.timu)
		{
			return false;
		}
		return false;
	}
	friend bool operator<(const team& a,const team& b)
	{
		if (a.timu < b.timu)
		{
			return true;
		}
		else if (a.timu == b.timu)
		{
			return a.fashi > b.fashi;
		}
		else if (a.timu > b.timu)
		{
			return false;
		}
		return false;
	}
	friend bool operator==(const team& a, const team& b)
	{
		return ( a.timu==b.timu ) && (a.fashi == b.fashi);
	}
	team operator=(const team& a)
	{
		this->timu = a.timu;
		this->fashi = a.fashi;
		this->name = a.name;
		return *this;
	}
	void add(int fashivalue)
	{
		this->timu++;
		this->fashi += fashivalue;
	}
};
team teams[100001];
int isqueue[100001];
int main()
{
	ios::sync_with_stdio(false);
	int n, m,t,p,nowrank=1;
	priority_queue<team> pe;
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
	{
		teams[i].name = i;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> t >> p;
		if (t == 1)
		{
			if (nowrank == 1)
			{
				teams[1].add(p);
			}
			else
			{
				team linshiteam;
				priority_queue<team> pe2;
				teams[1].add(p);
				nowrank = 1;
				int pesum = pe.size();
				fill(isqueue,isqueue+n+1,0);
				while (pesum--)
				{
					linshiteam = pe.top();
					if (linshiteam > teams[1])
					{
						pe2.push(linshiteam);
						pe.pop();
						if (isqueue[linshiteam.name] == 0)
						{
							++nowrank;
							++isqueue[linshiteam.name];
						}
					}
					else
					{
						break;
					}
				}
				pe.swap(pe2);
			}
		}
		else
		{
			teams[t].add(p);
			if (teams[t] > teams[1])
			{
				pe.push(teams[t]);
				if (isqueue[t] == 0)
				{
					++nowrank;
					++isqueue[t];
				}
			}
		}
		cout << nowrank << endl;
	}
	return 0;
}
