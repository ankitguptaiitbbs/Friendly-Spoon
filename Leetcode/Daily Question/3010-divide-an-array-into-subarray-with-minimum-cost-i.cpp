class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        vector<int> minis = {INT_MAX, INT_MAX};
        for(int i = 1; i < n; i++){
            if(nums[i] <= minis[0]){
                minis[1] = minis[0];
                minis[0] = nums[i];
            }
            else if(nums[i] < minis[1]){
                minis[1] = nums[i];
            }
            
        }
        return ans + minis[0] + minis[1];
    }
};
