class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        // Total numbers (expected range: 1 to n)
        int n = nums.size();

        // Array to count occurrences of each number (index 0 → number 1)
        vector<int> exists(n, 0);

        // Count how many times each number appears
        for (int i = 0; i < n; i++) {
            exists[nums[i] - 1]++;
        }

        int dup = 0;   // The number that appears twice
        int lost = 0;  // The number that is missing

        // Identify the duplicate and the missing number
        for (int i = 0; i < n; i++) {

            // If count is 0, number (i+1) is missing
            if (exists[i] == 0) {
                lost = i + 1;
            }
            // If count is 2, number (i+1) is duplicated
            else if (exists[i] == 2) {
                dup = i + 1;
            }
        }

        // Return {duplicate, missing}
        return {dup, lost};
    }
};
