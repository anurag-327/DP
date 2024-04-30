#include <bits/stdc++.h>
using namespace std;
int recursive(int arr[], int n, int k)
{
        if (n == 0)
                return 0;
        int minSteps = INT_MAX;
        int jump;
        for (int i = 1; i <= k; i++)
        {
                if (n - i >= 0)
                {
                        jump = recursive(arr, n - i, k) + abs(arr[n] - arr[n - i]);
                        minSteps = min(minSteps, jump);
                }
        }
        return minSteps;
}
int memo(int arr[], int n, int qb[], int k)
{
        //    TC: O(N)*k;
        //    SC: O(N)+O(N);
        if (n == 0)
                return 0;
        if (qb[n] != 0)
                return qb[n];
        int minSteps = INT_MAX;
        int jump;
        for (int i = 1; i <= k; i++)
        {
                if (n - i >= 0)
                {
                        jump = recursive(arr, n - i, k) + abs(arr[n] - arr[n - i]);
                        minSteps = min(minSteps, jump);
                }
        }
        qb[n] = minSteps;
        return minSteps;
}
int tabulation(int arr[], int n, int k)
{
        //    TC: O(N)*k;
        //    SC: O(N);
        int dp[n] = {0};
        dp[0] = 0;

        int jump;
        for (int i = 1; i < n; i++)
        {
                int minSteps = INT_MAX;
                for (int j = 1; j <= k; j++)
                {
                        if (i - j >= 0)
                        {
                                jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                                minSteps = min(minSteps, jump);
                        }
                }
                dp[i] = minSteps;
        }
        return dp[n - 1];
}
int spaceOptimised(int arr[], int n)
{
        // TC: O(N);
        // SC: O(K) -> k for list;
        // maintain k variables
        // NOT Required
}
int main()
{
        int n = 6, k = 2;
        int arr[n] = {30, 10, 60, 10, 60, 50};
        int qb[n];
        cout << recursive(arr, n - 1, k) << endl;
        cout << memo(arr, n - 1, qb, k) << endl;
        cout << tabulation(arr, n, k) << endl;
        //    cout<<spaceOptimised(arr,n);
}