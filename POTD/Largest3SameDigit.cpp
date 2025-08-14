class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int n = num.size();
        string ans = "";
        int i = 0;
        int CurrGreatest = INT_MIN;
        while (i < n - 2)
        {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2] && num[i] > CurrGreatest)
            {
                ans.erase();
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                ans.push_back(num[i]);
                CurrGreatest = num[i];
                i += 2;
            }
            else
            {

                i++;
            }
        }
        return ans;
    }
};