class Solution
{
public:
    bool hasSameDigits(string s)
    {

        if (s.size() == 1)
            return true;
        if (s.size() == 2)
        {
            return s[0] == s[1];
        }

        string t = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            int sum = (s[i] - '0' + s[i + 1] - '0') % 10;
            t += (sum + '0');
        }

        return hasSameDigits(t);
    }
};