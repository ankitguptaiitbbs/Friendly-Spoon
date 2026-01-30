// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // Initialize search boundaries
        int low = 1;        // First version
        int high = n;       // Last version
        
        // Variable to store the first bad version found
        int ans = high;

        // Binary search loop
        while (low <= high) {

            // Calculate mid this way to avoid integer overflow
            int mid = low + (high - low) / 2;

            // If mid version is bad
            if (isBadVersion(mid)) {
                // mid could be the first bad version, store it
                ans = mid;

                // Search the left half to find an earlier bad version
                high = mid - 1;
            }
            else {
                // mid is good, so the first bad version must be after it
                low = mid + 1;
            }
        }

        // Return the first bad version found
        return ans;
    }
};
