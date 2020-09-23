//01背包，物品数N，总重量M，重量w，价值v
//复杂度NM
for (int i = 1; i <= N; ++i)
{
    for (int j = M; j >= w[i]; --j)
    {
        dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
    }
}
//完全背包，物品数N，总重量M，重量w，价值v
//复杂度nm
for (int i = 1; i <= N; ++i)
{
    for (int j = w[i]; j <= M; ++j)
    {
        dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
    }
}
