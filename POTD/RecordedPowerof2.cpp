class Solution
{
public:
    bool check(int n)
    {
        string str = to_string(n);
        sort(str.begin(), str.end());
        int n1 = stoi(str);
        if (str[0] != '0' && same(n1))
        {
            return true;
        }
        while (next_permutation(str.begin(), str.end()))
        {
            int num = stoi(str);
            if (str[0] != '0' && same(num))
            {
                return true;
            }
        }
        return false;
    }
    bool same(int n)
    {
        if (n < 1)
        {
            return false;
        }
        while (n % 2 == 0)
        {
            n = n / 2;
        }
        if (n == 1)
        {
            return true;
        }
        return false;
    }
    bool revcheck(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int ld = n % 10;
            if (ld == 0)
            {
                return false;
            }
            sum = sum * 10 + ld;
            n /= 10;
        }
        return same(sum);
    }
    bool reorderedPowerOf2(int n)
    {

        return check(n);
    }
};