class Solution
{
public:
    int nextGreaterElement(int n)
    {
        int idx = -1;
        int j = 0;
        vector<int> digit;
        while (n > 0)
        {
            digit.push_back(n % 10);
            n = n / 10;
        }
        reverse(digit.begin(), digit.end());
        long long int size = digit.size();
        for (int i = size - 1; i > 0; i--)
        {
            if (digit[i] > digit[i - 1])
            {
                idx = i - 1;
                break;
            }
        }
        if (idx == -1)
            return -1;

        for (int k = size - 1; k > idx; k--)
        {
            if (digit[k] > digit[idx])
            {
                j = k;
                break;
            }
        }

        swap(digit[idx], digit[j]);
        reverse(digit.begin() + idx + 1, digit.end());
        long long ans = 0;
        for (int d : digit)
            ans = ans * 10 + d;
        if (ans > INT_MAX)
            return -1;
        return (int)ans;
    }
};