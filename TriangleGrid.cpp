#include <bits/stdc++.h>
using namespace std;
int recursive(vector<vector<int>> triangle, int i, int j, int n)
{
    //  TC: O(2^N*N);
    //  we will start form (0,0) here
    if (i == n - 1)
        return triangle[i][j];
    int down = triangle[i][j] + recursive(triangle, i + 1, j, n);
    int diagonal = triangle[i][j] + recursive(triangle, i + 1, j + 1, n);
    return min(down, diagonal);
}
int memo(vector<vector<int>> triangle, int i, int j, vector<vector<int>> &qb, int n)
{
    //  TC: O(N*M);
    //  SC: O(N)+O(N*N);
    if (i == n - 1)
        return triangle[i][j];
    if (qb[i][j] != 0)
        return qb[i][j];
    int down = triangle[i][j] + recursive(triangle, i + 1, j, n);
    int diagonal = triangle[i][j] + recursive(triangle, i + 1, j + 1, n);
    return qb[i][j] = min(down, diagonal);
}
int tabulation(vector<vector<int>> triangle, int n)
{
    //    TC: O(N*N);
    //    SC: O(N*N);
    // tabulation is oppo of recursive
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}
int spaceOptimised(vector<vector<int>> triangle, int n)
{
    //    TC: O(N*N);
    //    SC: O(N);
    vector<int> next(n, 0), curr(n, 0); // next row data
    for (int j = 0; j < n; j++)
    {
        next[j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + next[j];
            int diagonal = triangle[i][j] + next[j + 1];
            curr[j] = min(down, diagonal);
        }
        next = curr;
    }
    return next[0];
}
int main()
{
    int n = 4;
    vector<vector<int>> qb(n, vector<int>(n, 0));
    vector<vector<int>> arr = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    cout << recursive(arr, 0, 0, n) << endl;
    cout << memo(arr, 0, 0, qb, n) << endl;
    cout << tabulation(arr, n) << endl;
    cout << spaceOptimised(arr, n) << endl;
}