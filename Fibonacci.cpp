#include <bits/stdc++.h>
using namespace std;
void iterative(int n)
{
        int first = 0, second = 1, third;
        cout << first << " " << second << " ";
        for (int i = 3; i <= n; i++)
        {
                third = first + second;
                cout << third << " ";
                first = second;
                second = third;
        }
        cout << endl;
}
int recursive(int n)
{
        if (n == 0 || n == 1)
                return n;
        return recursive(n - 1) + recursive(n - 2);
}
int memo(int n, int qb[])
{
        // in memo we store rseult so we donot have to recompute
        if (n == 0 || n == 1)
                return n;
        if (qb[n] != 0)
                return qb[n];
        int fib1 = memo(n - 1, qb);
        int fib2 = memo(n - 2, qb);
        qb[n] = fib1 + fib2;
}
void tabulation(int n)
{
        int dp[n];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < n; i++)
        {
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        for (int i = 0; i < n; i++)
        {
                cout << dp[i] << " ";
        }
        cout << endl;
}
void printArray(int a[], int n)
{
        for (int i = 0; i < n; i++)
        {
                cout << a[i] << " ";
        }
        cout << endl;
}
int main()
{
        int n = 10;
        iterative(n);
        cout << recursive(n - 1) << endl;
        tabulation(n);
        int qb[n] = {0};
        memo(n - 1, qb);
        printArray(qb, n);
}