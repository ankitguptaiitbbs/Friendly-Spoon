#include <iostream>
using namespace std;

int main(){
    int t, legs;
    cin >> t;
    while(t--){
        cin >> legs;
        
        /* 1. If legs are odd (legs%2), no configuration is possible (0).
           2. If legs are even, the number of ways is (legs / 4) + 1.
              Example: legs = 6
              - 0 cows, 3 chickens
              - 1 cow, 1 chicken
              Total: (6/4) + 1 = 2 configurations.
        */
        int combo = legs%2 ? 0 : (legs/4 + 1);
        
        cout << combo << endl;
    }
}
