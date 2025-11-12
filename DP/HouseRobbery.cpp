#include <iostream>
using namespace std;
#include <bits/stdc++.h>
// recursive approach
int f(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[0];
    if (index < 0)
        return 0;

    int pick = nums[index] + f(index - 2, nums);
    int notpick = 0 + f(index - 1, nums);

    return max(pick, notpick);
}

// memoization approach
int f_memo(int index, vector<int> &nums, vector<int> &dp)
{

    if (index == 0)
        return nums[index];
    if (index < 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int pick = nums[index] + f_memo(index - 2, nums, dp);
    int notpick = 0 + f_memo(index - 1, nums, dp);
    return dp[index] = max(pick, notpick);
}

int f_tabulation(vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    dp[0] = nums[0];
    for (int index = 1; index < n; index++)
    {
        int pick = nums[index];

        if (index > 1)
        {
            pick += dp[index - 2];
        }
        int notpick = 0 + dp[index - 1];
        dp[index] = max(pick, notpick);
    }

    return dp[n - 1];
}
int f_tabulation_space_opt(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;

    for (int index = 1; index < n; index++)
    {
        int pick = nums[index];

        if (index > 1)
        {
            pick += prev2;
        }
        int notpick = 0 + prev;
        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    int n = nums.size();

    // Recursive approach
    cout << "Maximum Non-Adjacent Sum (Recursive): " << f(n - 1, nums) << endl; // tc: O(2^n) sc: O(n) for recursion stack

    // Memoization approach
    vector<int> dp_memo(n, -1);
    cout << "Maximum Non-Adjacent Sum (Memoization): " << f_memo(n - 1, nums, dp_memo) << endl; // tc: O(n) sc: O(n) for dp array + O(n) for recursion stack

    // Tabulation approach
    vector<int> dp_tab(n, 0);
    cout << "Maximum Non-Adjacent Sum (Tabulation): " << f_tabulation(nums, dp_tab) << endl; // tc: O(n) sc: O(n) for dp array

    // Space Optimized Tabulation approach
    cout << "Maximum Non-Adjacent Sum (Space Optimized): " << f_tabulation_space_opt(nums) << endl; // tc: O(n) sc: O(1)

    return 0;
}