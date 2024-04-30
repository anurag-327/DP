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

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    long long total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    if (total - d < 0 || (total - d) % 2 != 0)
        return 0;
    int k = (total - d) / 2; // our new target we need to achieve this target to get diff btw subsets as d
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
    // return solve(n-1,k,arr,dp);
    // return tabulation(arr.size(),k,arr);
    return spaceOptimised(arr.size(), k, arr);
}
