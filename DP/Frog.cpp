#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// Frog Jump - Recursive Approach
int frogjump(int index, vector<int> &height)
{
    if (index == 0)
        return 0;

    int left = frogjump(index - 1, height) + abs(height[index] - height[index - 1]);

    int right = INT_MAX;
    if (index > 1)
    {
        right = frogjump(index - 2, height) + abs(height[index] - height[index - 2]);
    }
    return min(left, right);
}
// Fog Jump - Memoization Approach
int frogjump_memo(int index, vector<int> &height, vector<int> &dp)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int left = frogjump_memo(index - 1, height, dp) + abs(height[index] - height[index - 1]);

    int right = INT_MAX;
    if (index > 1)
    {
        right = frogjump_memo(index - 2, height, dp) + abs(height[index] - height[index - 2]);
    }
    return dp[index] = min(left, right);
}
// Frog Jump - Tabulation Approach
int frogjump_tab(int n, vector<int> &height)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int left = dp[i - 1] + abs(height[i] - height[i - 1]);

        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}
// Frog Jump - Space Optimization Approach
int frogjum_space(int n, vector<int> &height)
{
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = prev2 + abs(height[i] - height[i - 2]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();
    cout << frogjump(n - 1, height) << endl;
    return 0;
}