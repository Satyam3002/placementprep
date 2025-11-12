#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minPathSumusingRecursion(int i, int j, vector<vector<int>> &triangle)
{
    if (i == triangle.size() - 1)
        return triangle[i][j];
    int down = triangle[i][j] + minPathSumusingRecursion(i + 1, j, triangle);
    int diagonal = triangle[i][j] + minPathSumusingRecursion(i + 1, j + 1, triangle);
    return min(down, diagonal);
}
int minPathSumusingMemoization(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
    {
        return dp[i][j] = triangle[i][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + minPathSumusingMemoization(i + 1, j, triangle, dp);
    int diagonal = triangle[i][j] + minPathSumusingMemoization(i + 1, j + 1, triangle, dp);
    return dp[i][j] = min(down, diagonal);
}

int minPathSumusingTabulation(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}
int main()
{
    int n = 4;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minPathSumusingRecursion(0, 0, triangle) << endl;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << minPathSumusingMemoization(0, 0, triangle, dp) << endl; // tc o(n^2) sc o(n^2)
    cout << minPathSumusingTabulation(triangle) << endl;            // tc o(n^2) sc o(n^2)
    return 0;
}