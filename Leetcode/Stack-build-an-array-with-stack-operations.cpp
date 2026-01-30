class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        // Stores the sequence of stack operations
        vector<string> ans;

        // Length of the target array
        int t = target.size();

        // Pointer to track the current index in target
        int j = 0;

        // Iterate through numbers from 1 to n
        // Stop early once all target elements are processed
        for(int i = 1; i <= n && j < t; i++) {

            // Always push the current number from the stream
            ans.push_back("Push");

            // If the current number is smaller than target[j],
            // it is not needed, so we immediately remove it
            if(i < target[j]) {
                ans.push_back("Pop");
            }
            else {
                // If it matches target[j], keep it
                // and move to the next target element
                j++;
            }
        }

        // Return the sequence of operations
        return ans;
    }
};
