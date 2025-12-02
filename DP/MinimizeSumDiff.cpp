#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 2;
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }

        // Calculate possible sum range: n elements, each in [-107, 107]
        // Worst case: n * (-107) to n * 107
        int minPossibleSum = n * (-107);
        int maxPossibleSum = n * 107;
        int offset = -minPossibleSum;
        int range = maxPossibleSum - minPossibleSum + 1;

        // dp[i][j] = true if we can achieve sum (j - offset) using exactly i elements
        vector<vector<bool>> dp(n + 1, vector<bool>(range, false));

        // Base case: sum 0 (at index offset) can be achieved with 0 elements
        dp[0][offset] = true;

        // Process each number
        for (int num : nums)
        {
            // Iterate backwards to avoid using the same element twice
            for (int count = n; count >= 1; count--)
            {
                for (int sumIdx = range - 1; sumIdx >= 0; sumIdx--)
                {
                    int actualSum = sumIdx - offset;
                    int prevSumIdx = actualSum - num + offset;
                    if (prevSumIdx >= 0 && prevSumIdx < range && dp[count - 1][prevSumIdx])
                    {
                        dp[count][sumIdx] = true;
                    }
                }
            }
        }

        int mini = 1e9;
        // Check all sums achievable with exactly n elements
        for (int sumIdx = 0; sumIdx < range; sumIdx++)
        {
            if (dp[n][sumIdx] == true)
            {
                int s1 = sumIdx - offset;
                mini = min(mini, abs(s1 - (totalSum - s1)));
            }
        }
        return mini;
    }
};