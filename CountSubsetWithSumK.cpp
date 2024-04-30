#include <bits/stdc++.h>
int mod = 1e9 + 7;
int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2; // pick or notPick 0
        if (target == 0 || target == arr[0])
            return 1; // notpick or pick
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int notPick = solve(index - 1, target, arr, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = solve(index - 1, target - arr[index], arr, dp);
    return dp[index][target] = (pick + notPick) % mod;
}
int tabulation(int n, int target, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int notPick = dp[i - 1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            dp[i][j] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][target];
}
int spaceOptimised(int n, int target, vector<int> &arr)
{
    vector<int> prev(target + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= target)
        prev[arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<int> curr(target + 1, 0);
        for (int j = 0; j <= target; j++)
        {
            int notPick = prev[j];
            int pick = 0;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = (pick + notPick) % mod;
        }
        prev = curr;
    }
    return prev[target];
}

int findWays(vector<int> &arr, int k)
{
    // Write your code here.
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
    // return solve(arr.size()-1,k,arr,dp);
    // return tabulation(arr.size(),k,arr);
    return spaceOptimised(arr.size(), k, arr);
}
