#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;
    
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        
        char last = s[n-1];
        int count = 0;
        for(int i = 0; i < n; i++) if(s[i] == last) count++;
        
        cout << n-count << endl;
    }
}
