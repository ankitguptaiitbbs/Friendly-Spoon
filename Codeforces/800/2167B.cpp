#include <iostream>
#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main(){
    int t, n;
    cin >> t;              // Number of test cases

    while(t--){
        cin >> n;          // Length of the strings
        
        string random, name;
        cin >> random;     // String s (letters on cubes)
        cin >> name;       // String t (girlfriend's name)
        
        // ---------------- Solution 1 (commented out) ----------------
        // Idea: Sort both strings and compare them
        /*
            sort(random.begin(), random.end());
            sort(name.begin(), name.end());
            
            if(random == name){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        */
        // ------------------------------------------------------------
        
        // Solution 2: Frequency counting
        // counts[i] represents the difference in occurrences
        // of character ('a' + i) between the two strings
        vector<int> counts(26, 0);
        
        for(int i = 0; i < n; i++){
            counts[random[i] - 'a']++;  // Count characters in random
            counts[name[i] - 'a']--;    // Subtract characters in name
        }
        
        // Check if all character counts are zero
        bool possible = true;
        for(int i = 0; i < 26; i++){
            if(counts[i] != 0){         // Mismatch found
                possible = false;
                break;
            }
        }
        
        // Output result
        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
