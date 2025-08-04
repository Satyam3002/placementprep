class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);  

        for (auto& t : trust) {
            trustCount[t[0]]--; 
            trustCount[t[1]]++; 
        }

        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1) {
                return i; 
            }
        }

        return -1; 
    }
};
