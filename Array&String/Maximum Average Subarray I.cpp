class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {

        int n = nums.size();
        double maxSum = 0;
        double sum = 0;
        double ans = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        maxSum = sum;
        ans = maxSum / k;

        for (int i = k; i < n; i++)
        {
            sum -= nums[i - k];
            sum += nums[i];

            maxSum = max(sum, maxSum);
            ans = maxSum / k;
        }

        return ans;
    }
};