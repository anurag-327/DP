int spaceOptimised(int n, vector<int> &arr)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int target = sum;
    vector<bool> prev(target + 1, 0);
    prev[0] = 1;
    if (arr[0] <= target)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(target + 1, 0);
        curr[0] = 1;
        for (int j = 1; j <= target; j++)
        {
            bool notPick = prev[j];
            bool pick = false;
            if (arr[i] <= j)
                pick = prev[j - arr[i]];
            curr[j] = pick || notPick;
        }
        prev = curr;
    }
    int mini = INT_MAX;
    for (int i = 0; i < target; i++)
    {
        if (prev[i] == true)
        {
            int s1 = i;
            int s2 = sum - i;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    return spaceOptimised(n, arr);
}