#include <iostream>
using namespace std;

int main() {
    // t: number of test cases
    // l: number of sections, a: starting section, b: jump size
    int t, l, a, b;
    cin >> t;
    
    while(t--) {
        cin >> l >> a >> b;
        
        // Start the pointer at the initial position 'a'
        int curr = a;
        // Keep track of the highest section number landed on
        int maxi = curr;
        
        // Simulate the spins until the pointer returns to the starting position
        do {
            // Move 'b' sections forward
            curr += b;
            // Use modulo to keep the pointer within the range [0, l-1]
            curr %= l;
            
            // Update the maximum prize if the current section is higher
            maxi = max(maxi, curr);
            
            // The sequence will eventually repeat; 
            // once we hit 'a' again, we've seen all possible landing spots.
        } while(curr != a);
        
        // Output the highest section number found in this cycle
        cout << maxi << endl;
    }
    
    return 0;
}
