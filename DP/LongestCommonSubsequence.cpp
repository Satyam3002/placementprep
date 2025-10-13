class Solution
{
public:
    int solveUsingMem(string &a, string &b, int i, int j,
                      vector<vector<int>> &dp)
    {
        if (i >= a.length())
        {
            return 0;
        }
        if (j >= b.length())
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            ans = 0 + max(solveUsingMem(a, b, i, j + 1, dp),
                          solveUsingMem(a, b, i + 1, j, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(text1.length() + 1,
                               vector<int>(text2.length() + 1, -1));
        int ans = solveUsingMem(text1, text2, i, j, dp);
        return ans;
    }
};