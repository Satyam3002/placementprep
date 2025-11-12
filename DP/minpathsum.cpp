#include <bits/stdc++.h>
using namespace std;

int minPathSumusingRecursion(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;

    int up = grid[i][j] + minPathSumusingRecursion(i - 1, j, grid);
    int left = grid[i][j] + minPathSumusingRecursion(i, j - 1, grid);
    return min(up, left);
}

int minPathSumusingMemoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + minPathSumusingMemoization(i - 1, j, grid, dp);
    int left = grid[i][j] + minPathSumusingMemoization(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << minPathSumusingRecursion(n - 1, m - 1, grid) << endl;
    cout << minPathSumusingMemoization(n - 1, m - 1, grid, dp) << endl;

    return 0;
}
