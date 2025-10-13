class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string a = s;
        reverse(a.begin(), a.end());
        int i = 0;
        int j = 0;
        vector<vector<int>> dp(s.length() + 1,
                               vector<int>(a.length() + 1, -1));
        int ans = solveUsingMem(s, a, i, j, dp);
        return ans;
    }

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
};