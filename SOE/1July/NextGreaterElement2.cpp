class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int idx = i % n;

            while (!st.empty() && st.top() <= nums[idx])
            {
                st.pop();
            }

            if (i < n && !st.empty())
            {
                nge[idx] = st.top();
            }

            st.push(nums[idx]);
        }

        return nge;
    }
};
