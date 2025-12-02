class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 2;
        int total = accumulate(nums.begin(), nums.end(), 0);

        // split nums into left & right halves
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // helper: generate all subset sums grouped by subset size
        auto generate = [&](vector<int> &arr)
        {
            int m = arr.size();
            vector<vector<int>> res(m + 1);
            for (int mask = 0; mask < (1 << m); mask++)
            {
                int sum = 0, cnt = 0;
                for (int i = 0; i < m; i++)
                {
                    if (mask & (1 << i))
                    {
                        sum += arr[i];
                        cnt++;
                    }
                }
                res[cnt].push_back(sum);
            }
            for (auto &vec : res)
                sort(vec.begin(), vec.end());
            return res;
        };

        auto leftSums = generate(left);
        auto rightSums = generate(right);

        int ans = INT_MAX;

        // try all splits: k from left, n-k from right
        for (int k = 0; k <= n; k++)
        {
            for (int s : leftSums[k])
            {
                int target = total / 2 - s; // want closest match
                auto &vec = rightSums[n - k];
                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end())
                {
                    int sum = s + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
                if (it != vec.begin())
                {
                    --it;
                    int sum = s + *it;
                    ans = min(ans, abs(total - 2 * sum));
                }
            }
        }

        return ans;
    }
};