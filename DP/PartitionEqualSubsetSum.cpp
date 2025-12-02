class Solution
{
public:
    bool isSum(vector<int> &nums, int target, int index,
               vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (index < 0)
            return false;
        if (index == 0)
        {
            return nums[0] == target;
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }

        bool notTake = isSum(nums, target, index - 1, dp);
        bool take = false;
        if (target >= nums[index])
        {
            take = isSum(nums, target - nums[index], index - 1, dp);
        }

        return dp[index][target] = notTake || take;
    }
    bool canPartition(vector<int> &nums)
    {
        int target = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            target += nums[i];
        }
        if (target % 2 != 0)
        {
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return isSum(nums, target / 2, nums.size() - 1, dp);
    }
};