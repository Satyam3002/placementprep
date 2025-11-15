#include <bits/stdc++.h>
using namespace std;

// using recursion
bool isSubsetSum(int arr[], int target, int index)
{
    if (target == 0)
        return true;

    if (index == 0)
        return arr[0] == target;

    bool notTake = isSubsetSum(arr, target, index - 1);
    bool take = false;
    if (arr[index] <= target)
    {
        take = isSubsetSum(arr, target - arr[index], index - 1);
    }
    return notTake || take;
}

// using memoization
bool isSubsetSumMemo(int arr[], int target, int index, vector<vector<int>> &dp)
{

    if (target == 0)
        return true;

    if (index == 0)
        return arr[0] == target;

    if (dp[index][target] != -1)
        return dp[index][target];

    bool notTake = isSubsetSumMemo(arr, target, index - 1, dp);
    bool take = false;
    if (arr[index] <= target)
    {
        take = isSubsetSumMemo(arr, target - arr[index], index - 1, dp);
    }
    return dp[index][target] = notTake || take;
}

// using tabulation
bool isSubsetSumTab(int arr[], int target, int n)
{
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int index = 1; index < n; index++)
    {
        for (int tar = 1; tar <= target; tar++)
        {

            bool notTake = dp[index - 1][tar];
            bool take = false;
            if (arr[index] <= tar)
            {
                take = dp[index - 1][tar - arr[index]];
            }
            dp[index][tar] = notTake || take;
        }
    }
    return dp[n - 1][target];
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int target = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << isSubsetSum(arr, target, n - 1) << endl;         // time complexity: O(2^n)
    cout << isSubsetSumMemo(arr, target, n - 1, dp) << endl; // time complexity: O(n*target)
    cout << isSubsetSumTab(arr, target, n) << endl;          // time complexity: O(n*target)
}