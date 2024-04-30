#include <bits/stdc++.h>
using namespace std;
int recursive(vector<vector<int>> arr, int i, int j)
{
    //    TC: O(2^m*n);
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (i > 0 && j > 0 && arr[i][j] == -1)
        return 0;
    int up = recursive(arr, i - 1, j);
    int right = recursive(arr, i, j - 1);
    return up + right;
}
int memo(vector<vector<int>> arr, int i, int j, vector<vector<int>> &qb)
{
    //    TC: O(N*M);
    //    SC: O(N)+O(N*M);

    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (i > 0 && j > 0 && arr[i][j] == -1)
        return 0;
    if (qb[i][j] != 0)
        return qb[i][j];
    int up = recursive(arr, i - 1, j);
    int right = recursive(arr, i, j - 1);
    return qb[i][j] = up + right;
}
int tabulation(vector<vector<int>> arr, int n, int m)
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
            else if (arr[i][j] == -1)
                dp[i][j] = 0;
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
int spaceOptimised(vector<vector<int>> arr, int n, int m)
{
    //    TC: O(N*M);
    //    SC: O(1);
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else if (arr[i][j] == -1)
                curr[j] = 0;
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
    int n = 3, m = 3;
    vector<vector<int>> qb(n, vector<int>(m, 0));
    vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {0, 1, 0}};
    cout << recursive(arr, n - 1, m - 1) << endl;
    cout << memo(arr, n - 1, m - 1, qb) << endl;
    cout << tabulation(arr, n, m) << endl;
    cout << spaceOptimised(arr, n, m) << endl;
}