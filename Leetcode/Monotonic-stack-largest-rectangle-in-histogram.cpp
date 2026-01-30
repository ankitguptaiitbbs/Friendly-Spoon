class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        heights.push_back(0);

        int max_area = 0;
        stack<int> st;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width = i - (st.empty() ? -1 : st.top()) - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        return max_area;
    }
};
