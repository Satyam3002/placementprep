#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int frogjump(vector<int> &height, int k, int index)
{
    if (index == 0)
    {
        return 0;
    }
    int minEnergy = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (index - j >= 0)
        {
            int jumpEnergy = frogjump(height, k, index - j) + abs(height[index] - height[index - j]);
            minEnergy = min(minEnergy, jumpEnergy);
        }
    }
    return minEnergy;
}

int frogjump_memo(vector<int> &height, int k, int index, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int minEnergy = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int jumpEnergy = frogjump_memo(height, k, index - i, dp) + abs(height[index] - height[index - i]);
            minEnergy = min(minEnergy, jumpEnergy);
        }
    }
    return dp[index] = minEnergy;
}
int frogjump_tab(vector<int> &height, int k, int n)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int minEnergy = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jumpEnergy = dp[i - j] + abs(height[i] - height[i - j]);
                minEnergy = min(minEnergy, jumpEnergy);
            }
        }
        dp[i] = minEnergy;
    }
    return dp[n - 1];
}

int main()
{
    vector<int> height = {10, 30, 40, 20};
    int n = height.size();
    int k = 2;
    vector<int> dp(n, -1);
    cout << frogjump_memo(height, k, n - 1, dp) << endl;
    return 0;
}