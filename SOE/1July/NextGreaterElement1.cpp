class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nexti(m, -1);
        vector<int> ans;
        unordered_map<int, int> mp;
        stack<int> st;
        st.push(-1);
        for (int i = m - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nexti[i] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < m; i++)
        {
            mp[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int indextofind = nums1[i];
            int indexis = mp[indextofind];
            ans.push_back(nexti[indexis]);
        }
        return ans;
    }
};