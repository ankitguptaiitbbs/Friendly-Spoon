class Solution {
public:
    // Helper function to perform an operation on two operands
    // a = second popped value (right operand)
    // b = first popped value (left operand)
    // c = operator
    int operation(int a, int b, string c){
        if(c == "+") return b + a;   // Addition
        if(c == "-") return b - a;   // Subtraction (order matters)
        if(c == "/") return b / a;   // Division (truncates toward zero)
        return b * a;                // Multiplication
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;               // Stack to store operands
        int n = tokens.size();

        // Traverse each token in the RPN expression
        for(int i = 0; i < n; i++){
            // If the current token is an operator
            if(tokens[i] == "+" || tokens[i] == "-" || 
               tokens[i] == "/" || tokens[i] == "*") {

                // Pop the top two operands from the stack
                int a = st.top();    // Right operand
                st.pop();
                int b = st.top();    // Left operand
                st.pop();

                // Perform the operation and push the result back
                st.push(operation(a, b, tokens[i]));
            }
            else{
                // If the token is a number, convert it to int and push onto stack
                st.push(stoi(tokens[i]));
            }
        }

        // Final result will be at the top of the stack
        return st.top();
    }
};
