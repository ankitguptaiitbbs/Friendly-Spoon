#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    while(t--){
        cin >> n;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            mini = min(temp, mini);
            maxi = max(temp, maxi);
        }
        cin >> x;
        
        string msg = (x >= mini && x <= maxi) ? "YES" : "NO";
        cout << msg << endl;
    }
}
