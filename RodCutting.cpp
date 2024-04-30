int tabulation(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notPick = 0 + dp[i - 1][j];
            int pick = INT_MIN;
            int rodlen = i + 1;
            if (rodlen <= j)
                pick = price[i] + dp[i][j - rodlen];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n - 1][n];
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    return tabulation(price, n);
}
