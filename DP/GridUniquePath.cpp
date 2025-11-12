#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int griduniquepath(int i, int j)
{

    if (i == 0 || j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int up = griduniquepath(i - 1, j);
    int left = griduniquepath(i, j - 1);
    return up + left;
}
int uniquepathusingmemo(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
        return 1;
    if (m < 0 || n < 0)
        return 0;

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int up = uniquepathusingmemo(m - 1, n, dp);
    int left = uniquepathusingmemo(m, n - 1, dp);
    dp[m][n] = up + left;
    return dp[m][n];
}
// tabulation
int uniquepathusingtabulation(int m, int n, vector<vector<int>> dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main()
{
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout << uniquepathusingmemo(m - 1, n - 1, dp) << endl;
    cout << uniquepathusingtabulation(2, 3, dp) << endl;
}