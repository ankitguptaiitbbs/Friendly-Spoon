class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> last(26,-1);
        for(int i = 0; i < n; i++) last[s[i]-'a'] = i;

        stack<char> st;
        set<char> seen;

        for(int i = 0; i < n; i++){
            if(seen.count(s[i])) continue;
            while(!st.empty() && st.top() >= s[i] && last[st.top() - 'a'] >= i){
                seen.erase(st.top());
                st.pop();
            }
            st.push(s[i]);
            seen.insert(st.top());
        }

        string lss = "";
        while(!st.empty()){
            lss += st.top();
            st.pop();
        }
        reverse(lss.begin(), lss.end());
        return lss;
    }
};
