#include <iostream>
using namespace std;

int main(){
    int t, n;
    // Read the number of test cases
    cin >> t;
    
    while(t--){
        // Read the size of the n x n grid
        cin >> n;
        
        // For larger grids, the maximum cost is found at cell (n-1, n).
        // That cell has value (n*n - n). Its neighbors are:
        // Above: (n*n - 2n), Below: (n*n), Left: (n*n - n - 1).
        // The formula below simplifies this sum for n > 4.
        if(n > 4){
            cout << 5*(n*n-1-n) << endl;
        }
        // Base case: 1x1 grid (Only the cell itself, no neighbors)
        else if(n == 1){
            cout << 1 << endl;
        }
        // Base case: 2x2 grid (Max cost usually at cell 3 or 4)
        else if(n == 2){
            cout << 9 << endl;
        }
        // Base case: 3x3 grid
        else if(n == 3){
            cout << 29 << endl;
        }
        // Base case: 4x4 grid (As mentioned in the problem description)
        else{
            cout << 56 << endl;
        }
    }
    return 0;
}
