class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int top = 0;
        queue<int> q;
        for(int i = 0; i < n; i++) q.push(students[i]);

        int skipped = 0;
        int non_eaters = n;

        while(skipped < non_eaters){
            if(q.front() == sandwiches[top]){
                top++;
                non_eaters--;
                q.pop();
                skipped = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                skipped++;
            }
        }
        return non_eaters;

    }
};
