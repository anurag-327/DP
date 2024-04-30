#include <bits/stdc++.h>
bool solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (arr[0] == target);
    if (dp[index][target] != -1)
        return dp[index][target];
    bool notPick = solve(index - 1, target, arr, dp);
    bool pick = false;
    if (arr[index] <= target)
        pick = solve(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = pick | notPick;
}
bool tabulation(int n, int target, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= target)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = pick || notPick;
        }
    }
    return dp[n - 1][target];
}
bool spaceOptimised(int n, int target, vector<int> &arr)
{
    vector<bool> prev(target + 1, 0);
    prev[0] = 1;
    if (arr[0] <= target)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(target + 1, 0);
        curr[0] = 1;
        for (int j = 1; j <= target; j++)
        {
            bool notPick = prev[j];
            bool pick = false;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = pick || notPick;
        }
        prev = curr;
    }
    return prev[target];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
    // return spaceOptimised(n,k,arr);
}