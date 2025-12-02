class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int col = obstacleGrid[0].size();
         if (obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][col-1] == 1){
            return 0;
         }

        vector<vector<int>> dp(rows, vector<int>(col, -1));
        return getuniquepaths(rows-1,col-1,obstacleGrid,dp);
    }
     int getuniquepaths(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp) {
        if(m<0 || n < 0) {
            return 0;
        }
        if (grid[m][n] == 1) return 0; 
        if(m== 0  && n == 0) {
            return 1;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        int up = getuniquepaths(m-1,n,grid,dp);
        int left = getuniquepaths(m,n-1,grid,dp);
        dp[m][n] = up + left;
        return dp[m][n];
    }
};