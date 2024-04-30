int maximumProfit(vector<int> &prices, int n, int fee)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(2, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                dp[index][buy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
            else
                dp[index][buy] = max(prices[index] + dp[index + 1][1] - fee, 0 + dp[index + 1][0]);
        }
    }
    return dp[0][1];
}
