#include <bits/stdc++.h>
int solve(int index, int w, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weight[0] <= w)
            return value[0]; // can pick
        return 0;
    }
    if (dp[index][w] != -1)
        return dp[index][w];
    int notPick = 0 + solve(index - 1, w, weight, value, dp);
    int pick = INT_MIN;
    if (weight[index] <= w)
        pick = value[index] + solve(index - 1, w - weight[index], weight, value, dp);
    return max(pick, notPick);
    return dp[index][w] = max(pick, notPick);
}
int tabulation(int n, int maxWeight, vector<int> weight, vector<int> value)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
        dp[0][i] = value[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notPick = 0 + dp[i - 1][j];
            int pick = INT_MIN;
            if (weight[i] <= j)
                pick = value[i] + dp[i - 1][j - weight[i]];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n - 1][maxWeight];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solve(n-1,maxWeight,weight,value,dp);
    return tabulation(n, maxWeight, weight, value);
}