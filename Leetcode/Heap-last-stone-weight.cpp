class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> heap;

        for(int i = 0; i < n; i++) heap.push(stones[i]);

        while(!heap.empty() && heap.size() >= 2){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();
            if(x != y) heap.push(max(x,y)-min(x,y));
        }
        if(!heap.empty()) return heap.top();
        return 0;
    }
};
