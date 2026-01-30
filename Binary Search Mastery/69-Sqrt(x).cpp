class Solution {
public:
    int mySqrt(int x) {
        // Binary search range:
        // Square root of x lies between 0 and x
        int low = 0;
        int high = x;

        // Variable to store the final answer
        int ans = 0;

        // Perform binary search
        while (low <= high) {
            // Calculate mid safely to avoid overflow
            long long mid = low + (high - low) / 2;

            // If mid^2 is less than or equal to x,
            // mid is a possible answer
            if (mid * mid <= x) {
                ans = mid;        // store the current valid result
                low = mid + 1;    // try to find a larger square root
            } 
            // If mid^2 is greater than x,
            // we need to search in the left half
            else {
                high = mid - 1;
            }
        }

        // Return the integer square root (rounded down)
        return ans;
    }
};
