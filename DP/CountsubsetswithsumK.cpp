#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int Fusingrecursion(int ind, int sum, vector<int> &arr)
{
    if (sum == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[0] == sum);
    }
    int nottake = Fusingrecursion(ind - 1, sum, arr);
    int take = 0;
    if (arr[ind] <= sum)
    {
        take = Fusingrecursion(ind - 1, sum - arr[ind], arr);
    }
    return nottake + take;
}

int Fusingmemoization(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[0] == sum);
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    int nottake = Fusingmemoization(ind - 1, sum, arr, dp);
    int take = 0;
    if (arr[ind] <= sum)
    {
        take = Fusingmemoization(ind - 1, sum - arr[ind], arr, dp);
    }
    return dp[ind][sum] = nottake + take;
}

int countsubset(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return Fusingmemoization(n - 1, target, arr, dp);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;
    cout << countsubset(arr, target) << endl;
    return 0;
}