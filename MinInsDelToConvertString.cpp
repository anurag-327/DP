class Solution
{
public:
    int spaceOptimized(int n, int m, string s, string t)
    {
        vector<int> prev(m + 1, 0);
        // base
        for (int i = 1; i <= n; i++)
        {
            vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int len = spaceOptimized(n, m, word1, word2);
        return n + m - (2 * len);
    }
};