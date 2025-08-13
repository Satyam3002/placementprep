class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        long long ans = 1;
        while (ans <= n)
        {
            if (ans == n)
                return true;
            ans *= 3;
        }

        return false;
    }
};