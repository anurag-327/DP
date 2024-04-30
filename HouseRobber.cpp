#include <bits/stdc++.h>
using namespace std;
int spaceOptimised(vector<int> arr)
{
        //    TC: O(N);
        //    SC: O(1);
        int n = arr.size();
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
        // TC 0(2*N) -> O(N)
        int n = 4;
        int arr[n] = {1, 3, 2, 1};
        if (n == 1)
                return arr[0];
        vector<int> temp1, temp2;
        // two options take first n-1 elements or last n-1 elements print max of two combinations
        for (int i = 0; i < n; i++)
        {
                if (i != 0)
                        temp1.push_back(arr[i]);
                if (i != n - 1)
                        temp2.push_back(arr[i]);
        }
        cout << max(spaceOptimised(temp1), spaceOptimised(temp2));
}