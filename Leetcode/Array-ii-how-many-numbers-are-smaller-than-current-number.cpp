class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Number of elements in the array
        int n = nums.size();

        // ans[i] will store how many numbers are smaller than nums[i]
        vector<int> ans(n, 0);

        // For each index i, count how many nums[j] are smaller than nums[i]
        for(int i = 0; i < n; i++){
            // Check all other indices j
            for(int j = 0; j < n; j++){
                // j must be different from i as required by the problem
                if(i == j) continue;

                // If nums[j] is smaller than nums[i],
                // then j is a valid index and we increment the count
                if(nums[j] < nums[i]) 
                    ans[i]++;
            }
        }

        // Return the array containing the counts for each index
        return ans;
    }
};
