class Solution
{
public:
    int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
            return (amount % coins[index] == 0); // 0 or 1
        if (dp[index][amount] != -1)
            return dp[index][amount];
        int notPick = solve(index - 1, amount, coins, dp);
        int pick = 0;
        if (coins[index] <= amount)
            pick = solve(index, amount - coins[index], coins, dp);
        return dp[index][amount] = pick + notPick;
    }
    int spaceOptimised(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> curr(amount + 1, -1);
            for (int j = 0; j <= amount; j++)
            {
                int notPick = prev[j];
                int pick = 0;
                if (coins[i] <= j)
                    pick = curr[j - coins[i]];
                curr[j] = pick + notPick;
            }
            prev = curr;
        }
        return prev[amount];
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // return solve(n-1,amount,coins,dp);
        return spaceOptimised(amount, coins);
    }
};