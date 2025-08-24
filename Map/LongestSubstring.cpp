class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (mp.find(ch) != mp.end() && mp[ch] >= start)
            {
                start = mp[ch] + 1;
            }

            mp[ch] = i;
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
