#include <iostream>
#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main(){
    int t, n;
    cin >> t;              // Number of test cases
    
    while(t--){
        cin >> n;          // Number of toys in this test case
        
        vector<int> nums(n);   // Store toy values
        
        // even_odd.first  -> whether there is at least one even number
        // even_odd.second -> whether there is at least one odd number
        pair<bool,bool> even_odd = {false, false};
        
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            
            // Check parity of current number
            if(nums[i] % 2){
                // Odd number found
                even_odd.second = true;
            }
            else{
                // Even number found
                even_odd.first = true;
            }
        }
        
        // If there is at least one even AND one odd number,
        // then any permutation is possible using valid swaps,
        // so we can fully sort to get lexicographically smallest array
        if(even_odd.first && even_odd.second){
            sort(nums.begin(), nums.end());
        }
        
        // Output the resulting sequence
        for(int i = 0; i < n; i++)
            cout << nums[i] << " ";
        cout << endl;
    }
}
