class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        vector<int> has_to_buy(tickets.begin(), tickets.end());

        int curr = 0;
        int time = 0;
        while(true){
            if(has_to_buy[curr]){
                has_to_buy[curr]--;
                time++;
                if(curr == k && !has_to_buy[curr]) return time;
            }
            curr++;
            curr %= n;
        }
        return -1;
    }
};
