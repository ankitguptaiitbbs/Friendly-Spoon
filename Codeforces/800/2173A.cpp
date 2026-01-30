#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k;
    
    // Read the number of test cases
    cin >> t;
    while(t--){
        // n = number of classes, k = forced awake duration after an important class
        cin >> n >> k;
        string s;
        cin >> s;
        
        // awake_count: tracks how many remaining classes we are forced to stay awake for
        // sleep_classes: accumulator for the total number of classes we can sleep through
        int awake_count = 0;
        int sleep_classes = 0;
        
        for(int i = 0; i < n; i++){
            // If the current class is important (1)
            if(s[i] == '1'){
                // Reset the awake timer to k; we must stay awake for the next k classes
                awake_count = k;
            }
            else{
                // If the class is not important (0) and the awake timer is 0, we can sleep
                if(!awake_count) sleep_classes++;
                
                // If we were in a forced awake state, decrement the timer but don't go below 0
                awake_count = max(awake_count-1, 0);
            }
        }
        
        // Output the result for the current test case
        cout << sleep_classes << endl;
    }
}
