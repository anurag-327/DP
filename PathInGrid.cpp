#include <bits/stdc++.h>
using namespace std;
int recursive(int i, int j)
{
    //    TC: O(2^m*n);
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = recursive(i - 1, j);
    int right = recursive(i, j - 1);
    return up + right;
}
int memo(int i, int j, vector<vector<int>> &qb)
{
    //    TC: O(N*M);
    //    SC: O(N)+O(N*M);

    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (qb[i][j] != -1)
        return qb[i][j];
    int up = recursive(i - 1, j);
    int right = recursive(i, j - 1);
    return qb[i][j] = up + right;
}
int tabulation(int n, int m)
{
    //    TC: O(N*M);
    //    SC: O(N*M);
    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n - 1][m - 1];
}
int spaceOptimised(int n, int m)
{
    //    TC: O(N);
    //    SC: O(1);
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}
int main()
{
    int n = 2, m = 2;
    vector<vector<int>> qb(n, vector<int>(m, -1));
    cout << recursive(n - 1, m - 1) << endl;
    cout << memo(n - 1, m - 1, qb) << endl;
    cout << tabulation(n, m) << endl;
    cout << spaceOptimised(n, m) << endl;
}