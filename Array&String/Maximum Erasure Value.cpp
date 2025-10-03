class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_map<int, int> mpp;
        int maxSum = 0;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            mpp[nums[right]]++;
            sum += nums[right];

            while (mpp[nums[right]] > 1)
            {
                mpp[nums[left]]--;
                sum -= nums[left];
                if (mpp[nums[left]] == 0)
                {
                    mpp.erase(nums[left]);
                }
                left++;
            }

            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};