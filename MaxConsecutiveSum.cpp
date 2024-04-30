#include <bits/stdc++.h>
using namespace std;
int recursive(int arr[], int n)
{
        //    TC: O(2^n);
        if (n == 0)
                return arr[n];
        if (n < 0)
                return 0;
        int pick = arr[n] + recursive(arr, n - 2);
        int nonPick = 0 + recursive(arr, n - 1);
        return (max(pick, nonPick));
}
int memo(int arr[], int n, int qb[])
{
        //    TC: O(N);
        //    SC: O(N)+O(N);
        if (n == 0)
                return arr[0];
        if (n < 0)
                return 0;
        if (qb[n] != 0)
                return qb[n];
        int pick = arr[n] + recursive(arr, n - 2);
        int nonPick = 0 + recursive(arr, n - 1);
        qb[n] = max(pick, nonPick);
        return (max(pick, nonPick));
}
int tabulation(int arr[], int n)
{
        //    TC: O(N);
        //    SC: O(N);
        int dp[n];
        dp[0] = arr[0];
        int pick, nonPick;
        for (int i = 1; i < n; i++)
        {
                if (i - 2 < 0)
                        pick = arr[i] + 0;
                else
                        pick = arr[i] + dp[i - 2];
                nonPick = 0 + dp[i - 1];
                dp[i] = max(pick, nonPick);
        }
        return dp[n - 1];
}
int spaceOptimised(int arr[], int n)
{
        //    TC: O(N);
        //    SC: O(1);
        // dp[i-2]=first dp[i-1]=second
        int dp[n];
        int first = arr[0], second = arr[0];
        int pick, nonPick;
        for (int i = 1; i < n; i++)
        {
                if (i - 2 < 0)
                        pick = arr[i] + 0;
                else
                        pick = arr[i] + first;
                nonPick = 0 + second;
                first = second;
                second = max(pick, nonPick);
        }
        return second;
}
int main()
{
        int n = 3;
        int arr[n] = {2, 3, 2};
        int qb[n] = {0};
        cout << recursive(arr, n - 1) << endl;
        cout << memo(arr, n - 1, qb) << endl;
        cout << tabulation(arr, n) << endl;
        cout << spaceOptimised(arr, n);
}