class Solution
{
public:
    int mod = 1e9 + 7;
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
    int findTargetSumWays(vector<int> &arr, int d)
    {
        int n = arr.size();
        long long total = 0;
        for (int i = 0; i < n; i++)
            total += arr[i];
        if (total - d < 0 || (total - d) % 2 != 0)
            return 0;
        int k = (total - d) / 2; // our new target we need to achieve this target to get diff btw subsets as d
        return spaceOptimised(arr.size(), k, arr);
    }
};