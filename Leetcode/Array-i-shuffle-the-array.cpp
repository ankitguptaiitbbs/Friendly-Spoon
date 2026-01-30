class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // Create an answer array of size 2n
        vector<int> ans(2 * n);

        // Loop through the first n elements
        for (int i = 0; i < n; i++) {
            // Place xi at even indices: 0, 2, 4, ...
            ans[2 * i] = nums[i];

            // Place yi at odd indices: 1, 3, 5, ...
            ans[2 * i + 1] = nums[i + n];
        }

        // Return the shuffled array
        return ans;
    }
};
