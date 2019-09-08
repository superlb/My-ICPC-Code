#include <cstdio>
#include <algorithm>
#define N 100
using namespace std;
struct ant_type
{
	int pos;
	char name[11];
}ant[N];
struct event_type
{
	int drop_time;
	char dir;
}events[N];
bool cmp_ant(const ant_type& p, const ant_type& q)
{
	return p.pos < q.pos;
}
bool cmp_event(const event_type& p, const event_type& q)
{
	return p.drop_time < q.drop_time;
}
int main()
{
	char dir[2];
	int i, k, n, L, R, T;
	scanf("%d", &T);
	for (k = 1; k <= T; ++k)
	{
		scanf("%d%d", &n, &L);
		for (i = 0; i < n; i++)
		{
			scanf("%s%d%s", ant[i].name, &ant[i].pos, dir);
			events[i].dir = dir[0];
			events[i].drop_time = (dir[0] == 'L' ? ant[i].pos : L - ant[i].pos);
		}
		sort(ant, ant + n, cmp_ant);
		sort(events, events + n, cmp_event);
		printf("Case #%d:\n", k);
		L = 0; R = n - 1;
		for (i = 0; i < n; i++)
		{
			if (events[i].dir == 'L')
			{
				printf("%d %s\n", events[i].drop_time, ant[L].name);
				L++;
			}
			else
			{
				printf("%d %s\n", events[i].drop_time, ant[R].name);
				R--;
			}
		}
	}
	return 0;
}
