class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        stack<int> st;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--)
        {
            int num = nums2[i];
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                map[num] = -1;
            }
            else
            {
                map[num] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for (int num : nums1)
        {
            ans.push_back(map[num]);
        }

        return ans;
    }
};