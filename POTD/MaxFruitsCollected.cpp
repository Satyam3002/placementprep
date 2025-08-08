class Solution
{
public:
    int maxCollectedFruits(vector<vector<int>> &grid)
    {
        int n = (int)grid.size();
        int total = 0;

        for (int i = 0; i < n; i++)
            total += grid[i][i];

        for (int phase = 0; phase < 2; phase++)
        {
            if (phase == 1)
            {
                for (int r = 0; r < n; r++)
                {
                    for (int c = r + 1; c < n; c++)
                    {
                        swap(grid[r][c], grid[c][r]);
                    }
                }
            }

            vector<int> prevRow(n, -1), currRow(n, -1);
            prevRow[n - 1] = grid[0][n - 1];

            for (int rowIdx = 1; rowIdx < n - 1; rowIdx++)
            {
                fill(currRow.begin(), currRow.end(), -1);

                for (int col = 0; col < n; col++)
                {
                    if (prevRow[col] < 0)
                        continue;

                    if (col > 0)
                        currRow[col - 1] = max(currRow[col - 1], prevRow[col] + grid[rowIdx][col - 1]);

                    if (col < n - 1)
                        currRow[col + 1] = max(currRow[col + 1], prevRow[col] + grid[rowIdx][col + 1]);

                    currRow[col] = max(currRow[col], prevRow[col] + grid[rowIdx][col]);
                }
                prevRow.swap(currRow);
            }
            total += prevRow[n - 1];
        }

        return total;
    }
};