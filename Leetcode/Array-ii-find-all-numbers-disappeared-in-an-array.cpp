class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Initialize ans with all numbers from 1 to n
        // ans[i] = i + 1 represents that (i+1) is assumed present initially
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = i + 1;

        // Mark numbers that appear in nums
        // If nums[i] exists, set ans[nums[i] - 1] to 0
        for (int i = 0; i < n; i++)
            ans[nums[i] - 1] = 0;

        // Remove all zeros from ans
        // Zeros represent numbers that appeared in nums
        for (int i = 0; i < ans.size(); i++) {
            // While current index is valid and value is zero
            while (i < ans.size() && ans[i] == 0) {
                // Move zero to the end
                swap(ans[i], ans[ans.size() - 1]);
                // Remove the last element (which is zero)
                ans.pop_back();
            }
        }

        // Remaining elements are the disappeared numbers
        return ans;
    }
};
