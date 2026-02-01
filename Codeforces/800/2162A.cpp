#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int temp;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> temp;
            maxi = max(temp, maxi);
        }
        cout << maxi << endl;
    }
}
