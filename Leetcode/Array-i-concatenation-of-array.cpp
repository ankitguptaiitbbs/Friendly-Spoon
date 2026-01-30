class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        
        // Create a result array of size 2*n
        vector<int> ans(2 * n);

        // Loop through the original array
        for (int i = 0; i < n; i++) {
            // Copy element to the first half
            ans[i] = nums[i];
            
            // Copy the same element to the second half
            ans[i + n] = nums[i];
        }

        // Return the concatenated array
        return ans;
    }
};
