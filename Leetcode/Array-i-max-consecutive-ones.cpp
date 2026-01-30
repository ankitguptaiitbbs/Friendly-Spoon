class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();      // Store the size of the array
        int count = 0;            // Counts current consecutive 1s
        int maxi = 0;             // Stores the maximum consecutive 1s found so far

        // Loop through each element in the array
        for(int i = 0; i < n; i++){
            count += nums[i];     // If nums[i] is 1, increment count; if 0, adds nothing

            if(!nums[i])          // If the current element is 0
                count = 0;        // Reset the consecutive count

            maxi = max(maxi, count); // Update the maximum if current count is larger
        }

        return maxi;              // Return the maximum consecutive 1s
    }
};
