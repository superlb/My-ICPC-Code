//最长上升子序列
//复杂度NlogN
fill(dp,dp+n,INF);
for (int i = 0; i < n; ++i)
{
    *lower_bound(dp,dp+n,a[i])=a[i];
    a[i] = lower_bound(dp, dp + n, INF) - dp;
}
