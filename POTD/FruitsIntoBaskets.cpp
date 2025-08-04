class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> mp;
        int maxlen = 0, start = 0;
        for (int i = 0; i < fruits.size(); i++)
        {
            mp[fruits[i]]++;
            while (mp.size() > 2)
            {
                mp[fruits[start]]--;
                if (mp[fruits[start]] == 0)
                {
                    mp.erase(fruits[start]);
                }
                start++;
            }
            maxlen = max(maxlen, i - start + 1);
        }
        return maxlen;
    }
};