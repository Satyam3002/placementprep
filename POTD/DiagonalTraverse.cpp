class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        int dia = 0;
        int i = 0, j = 0;

        while (dia != n + m - 1)
        {
            if (dia % 2 == 0)
            { // up-right
                while (j < m && i >= 0)
                {
                    ans.push_back(mat[i][j]);
                    j++;
                    i--;
                }
                dia++;

                if (j >= m)
                {
                    j = m - 1;
                    i += 2;
                }
                else
                {
                    i = 0;
                }
            }
            else
            { // down-left
                while (i < n && j >= 0)
                {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                dia++;

                if (i >= n)
                {
                    i = n - 1;
                    j += 2;
                }
                else
                {
                    j = 0;
                }
            }
        }
        return ans;
    }
};