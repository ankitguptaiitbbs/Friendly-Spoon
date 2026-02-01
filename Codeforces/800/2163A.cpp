#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        
        string msg = "YES";
        for(int i = 0; i < n-1; i++){
            if(i%2 && nums[i] != nums[i+1]){
                msg = "NO";
                break;
            }
        }
        cout << msg << endl;
    }
    return 0;
}
