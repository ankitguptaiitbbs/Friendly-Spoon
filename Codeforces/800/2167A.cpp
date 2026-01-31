#include <iostream>
using namespace std;
int main(){
    int t, a, b, c, d;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        string msg = (a==b && c == d && a == c) ? "YES" : "NO";
        cout << msg << endl;
    }
}
