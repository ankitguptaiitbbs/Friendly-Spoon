#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    // Read the number of test cases
    cin >> t;
    
    while(t--){
        // Read the size of the array for the current test case
        cin >> n;
        
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        
        stack<int> st;
        int count = 0;
        
        // Iterate backwards to check if an element can be "eaten" by a larger element to its left
        for(int i = n-1; i >= 0; i--){
            // If current element nums[i] is greater than an element to its right (st.top),
            // it means the right element can be removed according to problem rules.
            while(!st.empty() && nums[i] > st.top()){
                st.pop(); // Remove the smaller element
                count++;  // Increment the total operations count
            }
            // Push current element onto stack to potentially be eaten by something even larger to its left
            st.push(nums[i]);
        }
        // Output the maximum number of operations possible for this test case
        cout << count << endl;
    }
}
