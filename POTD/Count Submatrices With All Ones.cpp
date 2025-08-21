class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        int result = 0;

        for (int startRow = 0; startRow < m; startRow++)
        {
            vector<int> vec(n, 1);

            for (int endRow = startRow; endRow < m; endRow++)
            {
                for (int col = 0; col < n; col++)
                {
                    vec[col] = vec[col] & mat[endRow][col];
                }

                result += oneDArrayCount(vec);
            }
        }

        return result;
    }

    int oneDArrayCount(vector<int> &vec)
    {
        int count = 0;
        int length = 0;

        for (int x : vec)
        {
            if (x == 1)
            {
                length++;
                count += length; // add number of subarrays ending here
            }
            else
            {
                length = 0;
            }
        }

        return count;
    }
};
