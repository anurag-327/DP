class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    if (buy)
                        curr[buy][cap] = max(-prices[index] + ahead[0][cap], 0 + ahead[1][cap]);
                    else
                        curr[buy][cap] = max(prices[index] + ahead[1][cap - 1], 0 + ahead[0][cap]);
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};