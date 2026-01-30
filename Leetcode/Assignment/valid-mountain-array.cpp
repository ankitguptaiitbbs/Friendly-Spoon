class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;

        bool is_mountain = true;
        bool is_inc = true;
        int flips = 0;
        for(int i = 0; i < n-1; i++){
            if(arr[i] == arr[i+1]) return false;
            if(is_inc){
                if(arr[i] > arr[i+1]){
                    flips++;
                    is_inc = !is_inc;
                    if(i == 0) return false;
                }
            }
            else{
                if(arr[i] < arr[i+1]){
                    flips++;
                    is_inc = !is_inc;
                }
            }
        }
        return flips == 1;
    }
};
