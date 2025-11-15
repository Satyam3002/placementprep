#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxFallingPathSumUsingRecursion(vector<vector<int>> &matrix, int i, int j)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (j < 0 || j >= m)
    {
        return -1e9;
    }
    if (i == 0)
    {
        return matrix[0][j];
    }

    int up = matrix[i][j] + maxFallingPathSumUsingRecursion(matrix, i - 1, j);
    int leftDiagonal = matrix[i][j] + maxFallingPathSumUsingRecursion(matrix, i - 1, j - 1);
    int rightDiagonal = matrix[i][j] + maxFallingPathSumUsingRecursion(matrix, i - 1, j + 1);
    return max(up, max(leftDiagonal, rightDiagonal));
}
int maxFallingPathSumUsingMemoization(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (j < 0 || j >= m)
    {
        return -1e9;
    }
    if (i == 0)
    {
        return matrix[0][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = matrix[i][j] + maxFallingPathSumUsingMemoization(matrix, i - 1, j, dp);
    int leftDiagonal = matrix[i][j] + maxFallingPathSumUsingMemoization(matrix, i - 1, j - 1, dp);
    int rightDiagonal = matrix[i][j] + maxFallingPathSumUsingMemoization(matrix, i - 1, j + 1, dp);
    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}
int maxFallingPathSumUsingTabulation(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base row
    for (int j = 0; j < m; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = -1e9;
            if (j - 1 >= 0)
                leftDiagonal = matrix[i][j] + dp[i - 1][j - 1];

            int rightDiagonal = -1e9;
            if (j + 1 < m)
                rightDiagonal = matrix[i][j] + dp[i - 1][j + 1];

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    // Max in last row
    int maxSum = -1e9;
    for (int j = 0; j < m; j++)
        maxSum = max(maxSum, dp[n - 1][j]);

    return maxSum;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSum = -1e9;
    for (int j = 0; j < m; j++)
    {
        maxSum = max(maxSum, maxFallingPathSumUsingRecursion(matrix, n - 1, j));
    }
    cout << maxSum << endl;

    // using memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int j = 0; j < m; j++)
    {
        maxSum = max(maxSum, maxFallingPathSumUsingMemoization(matrix, n - 1, j, dp));
    }
    cout << maxSum << endl;
    // using tabulation
    maxSum = maxFallingPathSumUsingTabulation(matrix);
    cout << maxSum << endl;
}