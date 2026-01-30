#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    
    // Read the number of test cases
    cin >> t;
    while(t--){
        // Read the number of strings for the current test case
        cin >> n;
        
        vector <string> words(n);
        for(int i = 0; i < n; i++){
            cin >> words[i];
        }
        
        // Initialize the result string 's' with the first word
        string s = words[0];
        
        // Iterate through the remaining words and decide their placement
        for(int i = 1; i < n; i++){
            /* GREEDY CHOICE:
               Compare the two possible resulting strings:
               1. Prepending: words[i] + s
               2. Appending:  s + words[i]
               
               If (s + words[i]) is lexicographically larger than (words[i] + s),
               it means putting the current word at the beginning is better.
            */
            if (s + words[i] > words[i] + s){
                // Prepend the current word
                s = words[i] + s;
            }
            else{
                // Append the current word
                s += words[i];
            }
        }
        
        // Output the smallest possible string found for this test case
        cout << s << endl;
    }
    return 0;
}
