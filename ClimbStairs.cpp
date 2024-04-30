#include <bits/stdc++.h>
using namespace std;
int recursion(int n)
{
        if (n == 0) // if i am standing at 0 index then there is only option  left
                return 1;
        if (n == 1)
                return 1; // n-2 gives negative no which is not possible
        return recursion(n - 1) + recursion(n - 2);
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
        cout << recursion(4);
}