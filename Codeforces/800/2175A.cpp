#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    // Read the number of test cases
    cin >> t;
    
    while(t--){
        // Read the number of initially colored cells
        cin >> n;
        
        set<int> uniques;
        vector<int> nums(n);
        int ans = INT_MIN;
        
        // Read initial colors and track unique colors
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            uniques.insert(nums[i]);
            // Track the maximum color value present initially
            ans = max(ans, nums[i]);
        }
        
        // 'count' is the number of distinct colors currently on the ribbon
        int count = uniques.size();
        
        /**
         * The fairy colors the next cell with the current distinct count.
         * If the count is already a color in the ribbon, the count stays the same forever.
         * If not, the count increases. For 10^18 cells, the process will stabilize
         * at the smallest color value 'x' such that x is already in the ribbon
         * and x is greater than or equal to the initial unique count.
         */
        for(int i = 0; i < n; i++){
            // Look for the smallest existing color that can "stop" the increment
            if(nums[i] >= count){
                ans = min(ans, nums[i]);
            }
        }
        
        // Output the resulting color for the 10^18-th cell
        cout << ans << endl;
    }
}
