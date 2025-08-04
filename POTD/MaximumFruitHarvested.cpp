class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();
        int N = 2 * 1e5 + 1;
        vector<int> prefSum(N + 1, 0);
        for (auto a : fruits)
        {
            prefSum[a[0]] = a[1];
        }
        for (int i = 1; i < N; i++)
        {
            prefSum[i] += prefSum[i - 1];
        }
        int res = 0;
        for (int i = 0; i <= k; i++)
        {
            int left = i;
            int right = k - i;
            int l = max(startPos - left, 0);
            int r = min(startPos - 2 * left + k, N - 1);
            int curr = 0;
            // int  curr = (prefSum[startPos-1]-prefSum[startPos-i-1]) + (prefSum[startPos-2*i+k] - prefSum[startPos-1]);
            if (l <= r)
            {
                curr = prefSum[r] - (l > 0 ? prefSum[l - 1] : 0);
                res = max(res, curr);
            }

            right = i;
            left = k - i;
            l = max(startPos + 2 * right - k, 0);
            r = min(startPos + right, N - 1);
            cout << r;
            if (l <= r)
            {
                curr = prefSum[r] - (l > 0 ? prefSum[l - 1] : 0);
                res = max(res, curr);
            }
        }

        return res;
    }
};