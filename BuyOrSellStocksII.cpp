#include <bits/stdc++.h>
long solve(int index, int buy, long *values, int n, vector<vector<int>> &dp)
{
    if (index == n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    if (buy)
        return dp[index][buy] = max(-values[index] + solve(index + 1, 0, values, n, dp), 0 + solve(index + 1, 1, values, n, dp));
    else
        return dp[index][buy] = max(values[index] + solve(index + 1, 1, values, n, dp), 0 + solve(index + 1, 0, values, n, dp));
}
long tabulation(long *values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                dp[index][buy] = max(-values[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
            else
                dp[index][buy] = max(values[index] + dp[index + 1][1], 0 + dp[index + 1][0]);
        }
    }
    return dp[0][1];
}
long spaceOptimized(long *values, int n)
{
    vector<long> ahead(2, 0);
    vector<long> curr(2, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                curr[buy] = max(-values[index] + ahead[0], 0 + ahead[1]);
            else
                curr[buy] = max(values[index] + ahead[1], 0 + ahead[0]);
        }
        ahead = curr;
    }
    return ahead[1];
}
long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(2, -1));
    // return solve(0,1,values,n,dp);
    // return tabulation(values,n);
    return spaceOptimized(values, n);
}