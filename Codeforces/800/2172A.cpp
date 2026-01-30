#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Initialize a vector to store the scores of the three AI assistants
    vector<int> scores(3);
    
    // Read the three scores (Gemini, ChatGPT, and Claude) from standard input
    for(int i = 0; i < 3; i++) cin >> scores[i];

    // Sort the scores in non-decreasing order
    // After sorting: scores[0] is Min, scores[1] is Median, and scores[2] is Max
    sort(scores.begin(), scores.end());

    // Check if the difference between the maximum and minimum score is 10 or more
    if(scores[2]-scores[0] >= 10){
        // If the spread is too large, the judging is considered inconsistent
        cout << "check again" << endl;
    }
    else{
        // Otherwise, output "final" followed by the median score (the middle element)
        cout << "final " << scores[1] << endl;
    }
}
