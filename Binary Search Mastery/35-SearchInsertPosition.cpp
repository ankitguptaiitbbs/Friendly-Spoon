class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Initialize two pointers for binary search
        int low = 0;
        int high = nums.size() - 1;

        // Perform binary search
        while (low <= high) {
            // Calculate mid to avoid integer overflow
            int mid = low + (high - low) / 2;

            // If target is found, return its index
            if (nums[mid] == target) {
                return mid;
            }
            // If middle element is greater than target,
            // search in the left half
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            // If middle element is less than target,
            // search in the right half
            else {
                low = mid + 1;
            }
        }

        // If target is not found, 'low' will be the index
        // where the target should be inserted
        return low;
    }
};
