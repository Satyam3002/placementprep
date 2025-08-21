class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long count = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                count++;
            }
            if (nums[i] != 0 || i == nums.size() - 1)
            {
                if (count > 0)
                {
                    sum += (count * (count + 1)) / 2;
                    count = 0;
                }
            }
        }
        return sum;
    }
};
