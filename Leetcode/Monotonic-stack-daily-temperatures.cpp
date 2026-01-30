class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // Result array where wait[i] stores
        // number of days to wait for a warmer temperature
        vector<int> wait(n, 0);

        // Stack to store indices of days
        // It will be a MONOTONIC DECREASING stack
        // (temperatures at stored indices decrease from bottom to top)
        stack<int> st;

        // Traverse from right to left
        // because we are looking for the next warmer day in the future
        for (int i = n - 1; i >= 0; i--) {

            // Pop all indices whose temperatures
            // are less than or equal to current day's temperature
            // because they can never be the "next warmer day"
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is empty, there is no warmer day ahead
            // Otherwise, the top of the stack is the next warmer day
            wait[i] = st.empty() ? 0 : st.top() - i;

            // Push current index onto the stack
            // It may serve as the next warmer day for earlier elements
            st.push(i);
        }

        return wait;
    }
};
