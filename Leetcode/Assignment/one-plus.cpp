class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        int carry = 1;
        while(i >= 0 && digits[i] >= 9){
            digits[i] += carry;
            digits[i] %= 10;
            carry = 1;
            i--;
        }

        if(i == -1){
            digits.insert(digits.begin(), 1);
        }
        else{
            digits[i] += 1;
        }
        return digits;
    }
};
