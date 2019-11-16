#include <stdio.h>
struct time
{
	int h;
	int m;
	int s;
};
time plus(time a, time b)
{
	time res;
	res.h = a.h + b.h;
	res.m = a.m + b.m;
	res.s = a.s + b.s;
	if (res.s >= 60)
	{
		res.s -= 60;
		res.m++;
	}
	if (res.m >= 60)
	{
		res.m -= 60;
		res.h++;
	}
	return res;
}
int compare(time a, time b)
{
	if (a.h > b.h)
	{
		return 1;
	}
	else if (a.h < b.h)
	{
		return -1;
	}
	else
	{
		if (a.m > b.m)
		{
			return 1;
		}
		else if (a.m < b.m)
		{
			return -1;
		}
		else
		{
			if (a.s > b.s)
			{
				return 1;
			}
			else if (a.s < b.s)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}
int main()
{
	int N;
	time time1[20];
	time time2[20];
	time stime, gap, wait;
	int yesorno = 1;
	time what;
	time day;
	day.h = 23; day.m = 59; day.s = 59;
	scanf("%d0", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d:%d:%d", &time1[i].h, &time1[i].m, &time1[i].s);
		scanf("%d:%d:%d", &time2[i].h, &time2[i].m, &time2[i].s);
	}
	scanf("%d:%d:%d", &stime.h, &stime.m, &stime.s);
	scanf("%d:%d:%d", &gap.h, &gap.m, &gap.s);
	scanf("%d:%d:%d", &wait.h, &wait.m, &wait.s);
	what = stime;
	for (int i1 = 0; i1 < N; ++i1)
	{
		if (compare(what, time1[i1]) == -1)
		{
			yesorno = 0; break;
		}
		else
		{
			while (compare(time2[i1], plus(what, wait)) == 1)
			{
				what = plus(what, gap);
			}
			if (compare(what, day) == 1)break;
			if (i1 < N - 1)
			{
				if (compare(what, time1[i1 + 1]) == 1 || compare(what, time1[i1 + 1]) == 0)continue;
				if (compare(what, time2[i1]) == 1)
				{
					yesorno = 0;
					break;
				}
				else
				{
					what = time2[i1];
					yesorno = 0;
					break;
				}
			}
			else
			{
				if (compare(what, time2[i1]) == 1)
				{
					yesorno = 0;
					break;
				}
				else
				{
					what = time2[i1];
					yesorno = 0;
					break;
				}
			}
		}
	}
	if (N == 0)
	{
		yesorno = 0;
		what = stime;
	}
	if (yesorno == 1)
	{
		printf("%d", -yesorno);
	}
	else
	{
		printf("%02d:%02d:%02d", what.h, what.m, what.s);
	}
	return 0;
}
