#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveusingRecursion(int n, int k)
{
    // base case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }

    int ans = (solveusingRecursion(n - 1, k) + solveusingRecursion(n - 2, k)) * (k - 1);
    return ans;
}

int solveusingMem(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k * (k - 1);
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (solveusingMem(n - 1, k, dp) + solveusingMem(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

int solveusingTabulation(int n, int k)
{
    vector<int> dp(n + 1, -1);
    int prev2 = k;
    int prev1 = k + k * (k - 1);
    if (n == 1)
    {
        return prev2;
    }
    if (n == 2)
    {
        return prev1;
    }
    int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        // shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
    int n = 3, k = 2;
    cout << solveusingRecursion(n, k) << endl;
    vector<int> dp(n + 1, -1);
    cout << solveusingMem(n, k, dp) << endl;
    cout << solveusingTabulation(n, k) << endl;
    return 0;
}