class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0)
            return 1.0;
        if (n >= k - 1 + maxPts)
            return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double S = 1.0;
        double ans = 0.0;

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = S / maxPts;

            if (i < k)
            {
                S += dp[i];
            }
            else
            {
                ans += dp[i];
            }

            int out = i - maxPts;
            if (out >= 0 && out < k)
            {
                S -= dp[out];
            }
        }
        return ans;
    }
};
