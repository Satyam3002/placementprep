class Solution
{
public:
    void find(int pos, int sum, vector<int> &candidates, vector<int> &comb, vector<vector<int>> &ans)
    {
        if (sum == 0)
        {
            ans.push_back(comb);
            return;
        }
        while (pos < candidates.size() && sum >= candidates[pos])
        {
            // 1.pick krenge current element ko.
            comb.push_back(candidates[pos]);
            find(pos, sum - candidates[pos], candidates, comb, ans);
            // 2. skip krenge current element ko.
            pos++;
            comb.pop_back();
            // find(pos+1,target,comb,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        find(0, target, candidates, comb, ans);
        return ans;
    }
};