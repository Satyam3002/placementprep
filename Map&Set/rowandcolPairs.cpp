class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        map<vector<int>,int>rowCount;
        for(auto &row : grid) {
            rowCount[row]++;
        }   
        int count = 0;
        for (int j = 0; j < n; j++) {
            vector<int> col;
          for (int i = 0; i < m; i++) {  
            col.push_back(grid[i][j]);
          }
          count += rowCount[col];
        }
         return count;
    }
};