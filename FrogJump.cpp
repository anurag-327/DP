#include <bits/stdc++.h>
using namespace std;
int recursive(int arr[], int n)
{
        if (n == 0)
                return 0; // no cost in transition
        int cost1 = recursive(arr, n - 1) + abs(arr[n] - arr[n - 1]);
        int cost2 = INT_MAX;
        if (n > 1)
                cost2 = recursive(arr, n - 2) + abs(arr[n] - arr[n - 2]);
        return (min(cost1, cost2));
}
int memo(int arr[], int n, int qb[])
{
        //    TC: O(N);
        //    SC: O(N)+O(N);
        if (n == 0)
                return 0;
        if (qb[n] != 0)
                return qb[n];
        int cost1 = recursive(arr, n - 1) + abs(arr[n] - arr[n - 1]);
        int cost2 = INT_MAX;
        if (n > 1)
                cost2 = recursive(arr, n - 2) + abs(arr[n] - arr[n - 2]);
        qb[n] = min(cost1, cost2);
        return qb[n];
}
int tabulation(int arr[], int n)
{
        //    TC: O(N);
        //    SC: O(N);
        int dp[n] = {0};
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
                int cost1 = dp[i - 1] + abs(arr[i] - arr[i - 1]);
                int cost2 = INT_MAX;
                if (i > 1)
                        cost2 = dp[i - 2] + (arr[i] - arr[i - 2]);
                dp[i] = min(cost1, cost2);
        }
        return (dp[n - 1]);
}
int spaceOptimised(int arr[], int n)
{
        //    TC: O(N);
        //    SC: O(1);
        int first = 0, second = 0, third;
        for (int i = 1; i < n; i++)
        {
                int cost1 = second + abs(arr[i] - arr[i - 1]);
                int cost2 = INT_MAX;
                if (i > 1)
                        cost2 = first + (arr[i] - arr[i - 2]);
                third = min(cost1, cost2);
                first = second;
                second = third;
        }
        return third;
}
int main()
{
        int n = 6;
        int arr[n] = {30, 10, 60, 10, 60, 50};
        int qb[n];
        cout << recursive(arr, n - 1) << endl;
        cout << memo(arr, n - 1, qb) << endl;
        cout << tabulation(arr, n) << endl;
        cout << spaceOptimised(arr, n);
}