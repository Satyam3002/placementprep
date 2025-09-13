class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> freq(26, 0);
        int maxVowel = 0, maxConsonant = 0;

        for (char ch : s)
        {
            int idx = ch - 'a';
            freq[idx]++;

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                maxVowel = max(maxVowel, freq[idx]);
            }
            else
            {
                maxConsonant = max(maxConsonant, freq[idx]);
            }
        }

        return maxVowel + maxConsonant;
    }
};
