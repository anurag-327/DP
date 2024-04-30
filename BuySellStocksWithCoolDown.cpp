long solve(int index, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    if (buy)
        return dp[index][buy] = max(-prices[index] + solve(index + 1, 0, prices, n, dp), 0 + solve(index + 1, 1, prices, n, dp));
    else
        return dp[index][buy] = max(prices[index] + solve(index + 2, 1, prices, n, dp), 0 + solve(index + 1, 0, prices, n, dp));
}
int tabulation(int n, vector<int> &prices)
{
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                dp[index][buy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
            else
                dp[index][buy] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
        }
    }
    return dp[0][1];
}
int spaceOptimized(int n, vector<int> &prices)
{
    vector<int> curr(2, 0);
    vector<int> ahead1(2, 0);
    vector<int> ahead2(2, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
                curr[buy] = max(-prices[index] + ahead1[0], 0 + ahead1[1]);
            else
                curr[buy] = max(prices[index] + ahead2[1], 0 + ahead1[0]);
        }
        ahead2 = ahead1;
        ahead1 = curr;
    }
    return ahead1[1];
    ;
}
int stockProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    // vector<vector<int>> dp(n,vector<int>(2,-1));
    // return solve(0,1,prices,n,dp);
    // return tabulation(n,prices);
    return spaceOptimized(n, prices);
}