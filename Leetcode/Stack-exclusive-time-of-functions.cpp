class Solution { 
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        // Result array: times[i] = exclusive time of function i
        vector<int> times(n, 0);

        // Stack to keep track of currently running functions (by function id)
        stack<int> st;

        // prev stores the last timestamp we accounted for
        int prev = 0;

        // Process each log entry
        for(int i = 0; i < logs.size(); i++) {

            // Parse the log string: "id:start|end:time"
            string log = logs[i];
            stringstream ss(log);
            string part;

            // Extract function id
            getline(ss, part, ':');
            int id = stoi(part);

            // Extract whether it's a start or end log
            getline(ss, part, ':');
            bool is_start = (part == "start");

            // Extract timestamp
            getline(ss, part, ':');
            int time = stoi(part);

            // If a function starts
            if(is_start) {

                // If another function was running before this,
                // add the time it ran until now
                if(!st.empty()) {
                    times[st.top()] += time - prev;
                }

                // Push current function onto stack
                st.push(id);

                // Update prev to current start time
                prev = time;
            }
            else {
                // Function ends:
                // Add its execution time (inclusive of end timestamp)
                times[id] += time - prev + 1;

                // Remove function from stack
                st.pop();

                // Update prev to the next time unit after this function ends
                prev = time + 1;
            }
        }

        return times;
    }
};
