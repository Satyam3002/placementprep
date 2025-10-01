class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k)
    {
        int length = 0;
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
            {
                length++;
            }
        }
        ans = length;

        for (int i = k; i < s.size(); i++)
        {
            if (isVowel(s[i]))
            {
                length++;
            }
            if (isVowel(s[i - k]))
            {
                length--;
            }

            ans = max(length, ans);
        }
        return ans;
    }
};