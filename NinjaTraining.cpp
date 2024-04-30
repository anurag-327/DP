#include <bits/stdc++.h>
using namespace std;
int recursive(int arr[][3], int day, int last)
{
        //    TC: O(2^n);
        if (day == 0)
        {
                int maxi = INT_MIN;
                // return max possible
                for (int i = 0; i < 3; i++)
                {
                        if (i != last)
                                maxi = max(maxi, arr[0][i]);
                }
                return maxi;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
                if (i != last)
                {
                        int points = arr[day][i] + recursive(arr, day - 1, i);
                        maxi = max(maxi, points);
                }
        }
        return maxi;
}
int memo(int arr[][3], int day, int last, int qb[][3])
{
        //    TC: O(N*4*3);
        //    SC: O(N)+O(N*4);
        if (day == 0)
        {
                int maxi = INT_MIN;
                // return max possible
                for (int i = 0; i < 3; i++)
                {
                        if (i != last)
                                maxi = max(maxi, arr[0][i]);
                }
                qb[day][last] = maxi;
                return maxi;
        }
        if (qb[day][last] != 0)
                return qb[day][last];
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
                if (i != last)
                {
                        int points = arr[day][i] + recursive(arr, day - 1, i);
                        maxi = max(maxi, points);
                }
        }
        qb[day][last] = maxi;
        return maxi;
}
int tabulation(int arr[][3], int n)
{
        //  TC: O(N*4*3);
        //  SC: O(N*4);
        int dp[n][4];
        dp[0][0] = max(arr[0][1], arr[0][2]); // task 0 was already selected at day 0
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][2], arr[0][1])); // if n==1 only one day so task was selected previously

        int maxi = INT_MIN;
        int day = 1, last = 0, task = 0;
        for (day = 1; day < n; day++)
        {
                for (last = 0; last < 4; last++)
                {
                        dp[day][last] = 0;
                        for (task = 0; task < 3; task++)
                        {
                                if (task != last)
                                {
                                        int points = arr[day][task] + dp[day - 1][task];
                                        //                    maxi=max(maxi,points);
                                        dp[day][last] = max(dp[day][last], points);
                                }
                        }
                        //            dp[day][last]=maxi;
                }
        }
        return dp[n - 1][3];
}

int spaceOptimised(int arr[][3], int n)
{
        //    TC: O(N*4*3);
        //    SC: O(4);
        //    idea is to store all data in single arr[4]
        //    we just needed data of the previous row to compute present row
        vector<int> dp(4, 0);
        dp[0] = max(arr[0][1], arr[0][2]); // task 0 was already selected at day 0
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        dp[3] = max(arr[0][0], max(arr[0][1], arr[0][2])); // if n==1 only one day so task was selected previously

        int day = 1, last = 0, task = 0;
        for (day = 1; day < n; day++)
        {
                vector<int> temp(4, 0); // to store data of current day
                for (last = 0; last < 4; last++)
                {
                        temp[last] = 0;
                        for (task = 0; task < 3; task++)
                        {
                                if (task != last)
                                {
                                        temp[last] = max(temp[last], arr[day][task] + dp[task]);
                                }
                        }
                }
                dp = temp;
        }
        return dp[3];
}
int main()
{
        // n days  choose out of 3 tasks

        //    Sample 1
        //    int n=2;
        //    int arr[2][3]={{10,50,1},{5,100,11}};  // 110
        //    int qb[n][3]={0};

        //    Sample 2
        int n = 3;
        int arr[n][3] = {{10, 11, 19}, {4, 13, 7}, {1, 8, 13}}; // 45
        int qb[n][3] = {0};

        cout << recursive(arr, n - 1, 3) << endl;
        cout << memo(arr, n - 1, 3, qb) << endl;
        cout << tabulation(arr, n) << endl;
        cout << spaceOptimised(arr, n);
}