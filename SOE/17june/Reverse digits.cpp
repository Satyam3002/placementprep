class Solution
{
public:
    int reverseDigits(int n)
    {
        // Code here
        int left = n;
        int ans = 0;
        while (left != 0)
        {
            ans = ans * 10 + left % 10;
            left = left / 10;
        }
        return ans;
    }
};