class Solution
{
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> powers;
        int bit = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                powers.push_back(1 << bit);
            }

            bit++;
            n >>= 1;
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            long long product = 1;
            for (int i = q[0]; i <= q[1]; i++)
            {
                product = (product * powers[i]) % MOD;
            }
            ans.push_back((int)product);
        }

        return ans;
    }
};