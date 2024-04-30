#include <bits/stdc++.h>
int spaceOptimized(string s, string t)
{
    int n = s.size();
    int m = t.size();
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
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string t = s;
    reverse(t.begin(), t.end());
    return spaceOptimized(s, t);
}