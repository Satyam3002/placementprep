class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            int discount = st.empty() ? 0 : st.top();
            prices[i] -= discount;
            st.push(prices[i] + discount); 
        }

        return prices;

    }
};
