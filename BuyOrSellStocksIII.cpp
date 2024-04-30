#include <bits/stdc++.h>
int solve(int index, int buy, int cap, vector<int> &prices, int n)
{
    if (index == n || cap == 0)
        return 0;
    if (buy)
        return max(-prices[index] + solve(index + 1, 0, cap, prices, n), 0 + solve(index + 1, 1, cap, prices, n));
    else
        return max(prices[index] + solve(index + 1, 1, cap - 1, prices, n), 0 + solve(index + 1, 0, cap, prices, n));
}
int memoized(int index, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    if (index == n || cap == 0)
        return 0;
    if (dp[index][buy][cap] != -1)
        return dp[index][buy][cap];
    if (buy)
        return dp[index][buy][cap] = max(-prices[index] + solve(index + 1, 0, cap, prices, n), 0 + solve(index + 1, 1, cap, prices, n));
    else
        return dp[index][buy][cap] = max(prices[index] + solve(index + 1, 1, cap - 1, prices, n), 0 + solve(index + 1, 0, cap, prices, n));
}
int tabulation(vector<int> &prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                    dp[index][buy][cap] = max(-prices[index] + dp[index + 1][0][cap], 0 + dp[index + 1][1][cap]);
                else
                    dp[index][buy][cap] = max(prices[index] + dp[index + 1][1][cap - 1], 0 + dp[index + 1][0][cap]);
            }
        }
    }
    return dp[0][1][2];
}
int spaceOptimized(vector<int> &prices, int n)
{
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy)
                    curr[buy][cap] = max(-prices[index] + ahead[0][cap], 0 + ahead[1][cap]);
                else
                    curr[buy][cap] = max(prices[index] + ahead[1][cap - 1], 0 + ahead[0][cap]);
            }
        }
        ahead = curr;
    }
    return ahead[1][2];
}
int maxProfit(vector<int> &prices)
{
    // Write your code here
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // return solve(0,1,2,prices,n);
    // return memoized(0,1,2,prices,n,dp);
    // return tabulation(prices,n);
    return spaceOptimized(prices, n);
}