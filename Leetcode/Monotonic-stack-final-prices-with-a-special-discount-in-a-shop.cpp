class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        
        // This will store the final prices after applying the discount
        vector<int> final(n, 0);

        // Monotonic stack (non-increasing)
        // It stores candidate prices that can act as a discount
        stack<int> st;

        // Traverse from right to left so we can find
        // the first smaller or equal price to the right
        for (int i = n - 1; i >= 0; i--) {

            // Remove all prices from the stack that are greater
            // than the current price since they can't be a valid discount
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            // If stack is empty, no discount exists
            // Otherwise, top of stack is the nearest smaller/equal price
            final[i] = st.empty() ? prices[i] : prices[i] - st.top();

            // Push current price for future items on the left
            st.push(prices[i]);
        }

        return final;
    }
};
