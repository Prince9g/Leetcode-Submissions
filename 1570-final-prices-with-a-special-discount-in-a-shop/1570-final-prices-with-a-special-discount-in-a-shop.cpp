class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size = prices.size();
        vector<int> ans(size);
        stack<int> st;
        
        for(int i = size - 1; i >= 0; i--) {
            int curr = prices[i];
            // Pop elements from the stack that are greater than the current price
            while (!st.empty() && st.top() > curr) {
                st.pop();
            }
            // If stack is not empty, apply the discount
            if (!st.empty()) {
                ans[i] = curr - st.top();
            } else {
                // No discount available
                ans[i] = curr;
            }
            // Push the current price onto the stack
            st.push(curr);
        }
        
        return ans;
    }
};
