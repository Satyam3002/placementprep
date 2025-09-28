class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int n = gain.size();
        int maxi = 0;
        int currgain = 0;

        for (int i = 0; i < n; i++)
        {
            currgain = currgain + gain[i];
            maxi = max(maxi, currgain);
        }

        return maxi;
    }
};