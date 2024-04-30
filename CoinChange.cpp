class Solution
{
public:
    long long solve(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }
        if (dp[index][target] != -1)
            return dp[index][target];
        int notPick = 0 + solve(index - 1, target, coins, dp);
        int pick = 1e9;
        if (coins[index] <= target)
            pick = 1 + solve(index, target - coins[index], coins, dp);
        return dp[index][target] = min(pick, notPick);
    }
    int tabulation(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notPick = 0 + dp[i - 1][j];
                int pick = 1e9;
                if (coins[i] <= j)
                    pick = 1 + dp[i][j - coins[i]];
                dp[i][j] = min(pick, notPick);
            }
        }
        return dp[n - 1][amount];
    }
    int spaceOptimised(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, -1);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(amount + 1, -1);
            for (int j = 0; j <= amount; j++)
            {
                int notPick = 0 + prev[j];
                int pick = 1e9;
                if (coins[i] <= j)
                    pick = 1 + curr[j - coins[i]];
                curr[j] = min(pick, notPick);
            }
            prev = curr;
        }
        return prev[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // long long ans=solve(n-1,amount,coins,dp);
        // long long ans=tabulation(coins,amount);
        long long ans = spaceOptimised(coins, amount);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};